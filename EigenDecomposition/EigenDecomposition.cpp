#include <iostream>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;
void getCofactor(double matrix[100][100], double cofactorMatrix[100][100], int p, int q, int n);
void displayMatrix(double matrix[100][100], int n);
double determinant(double matrix[100][100], int n);
void adjoint(double matrix[100][100], double adj[100][100], int n);
bool inverse(double matrix[100][100], double inverse[100][100], int n);
int main()
{
	//Eigen Decomposition is only work with matrix which has the same number of columns as rows
	int n;
	cin >> n;
	MatrixXd m(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int value;
			cin >> value;
			m(i, j) = value;
		}
	}
	//Step 1: Calculate eigen values
	Eigen::EigenSolver<MatrixXd> es(m);
	cout << "Eigen Values: " << endl;
	cout << es.pseudoEigenvalueMatrix() << endl;
	//Step 2: Calculate eigen vectors
	
	cout << "Eigen Vectors: " << endl;
	MatrixXd eigenVectors = es.pseudoEigenvectors();
	double usedMatrix[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			usedMatrix[i][j] = eigenVectors(i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		double minOfColumns = usedMatrix[0][i];
		for (int j = 1; j < n; j++)
		{
			if (usedMatrix[j][i] < minOfColumns)
			{
				minOfColumns = usedMatrix[j][i];
			}
		}
		for (int j = 0; j < n; j++)
		{
			usedMatrix[j][i] /= minOfColumns;
		}
	}
	displayMatrix(usedMatrix, n);
	//Step 3 : Calculate Inverse Matrix of Eigen Values Matrix
	double inverseMatrix[100][100];
	cout << "Inverse Matrix:" << endl;
	if (inverse(usedMatrix, inverseMatrix, n))
	{
		displayMatrix(inverseMatrix, n);
	}
	
}
void getCofactor(double matrix[100][100], double cofactorMatrix[100][100], int p, int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element
			//  which are not in given row and column
			if (row != p && col != q)
			{
				cofactorMatrix[i][j++] = matrix[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
double determinant(double matrix[100][100], int n)
{
	double D = 0; // Initialize result

	//  Base case : if matrix contains single element
	if (n == 1)
		return matrix[0][0];

	double temp[100][100]; // To store cofactors

	int sign = 1;  // To store sign multiplier

	 // Iterate for each element of first row
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of A[0][f]
		getCofactor(matrix, temp, 0, f, n);
		D += sign * matrix[0][f] * determinant(temp, n - 1);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}
void adjoint(double matrix[100][100], double adj[100][100], int n)
{
	if (n == 1)
	{
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of A[][]
	int sign = 1;
	double temp[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Get cofactor of A[i][j]
			getCofactor(matrix, temp, i, j, n);

			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j][i] = (sign) * (determinant(temp, n - 1));
		}
	}
}
bool inverse(double matrix[100][100], double inverse[100][100], int n)
{
	// Find determinant of A[][]
	int det = determinant(matrix, n);
	if (det == 0)
	{
		cout << "Singular matrix, can't find its inverse";
		return false;
	}

	// Find adjoint
	double adj[100][100];
	adjoint(matrix, adj, n);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)"
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}
void displayMatrix(double matrix[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}