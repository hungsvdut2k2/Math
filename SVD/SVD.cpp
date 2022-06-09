#include <Eigen/Dense>
#include <iostream>
using Eigen::MatrixXd;
using namespace std;
void displayMatrix(double matrix[100][100], int rows, int columns);
void Transpose(double matrix[100][100], double transposeMatrix[100][100], int rows, int columns);
void matrixMultiplication(double matrixA[100][100], double matrixB[100][100], double resMatrix[100][100], int rows, int columns);
int main()
{
	int rows;
	int columns;
	double matrix[100][100];
	cin >> rows >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
	//SVD can be used for rectangular matrix
	//so at the first step, we need to mutiply A^T with A to form a square matrix
	//Step 1: Calculate A * A^T
	double transposeMatrix[100][100];
	Transpose(matrix, transposeMatrix, rows, columns);
	cout << "Transpose Matrix: " << endl;
	displayMatrix(transposeMatrix, columns, rows);
	cout << endl;
	double resMatrix[100][100];
	matrixMultiplication(transposeMatrix, matrix, resMatrix, columns, rows);
	cout << "A^T * A: " << endl;
	displayMatrix(resMatrix, columns, columns);
	cout << endl;
	//Step 2: Find Eigen Values
	MatrixXd m(columns, columns);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m(i, j) = resMatrix[i][j];
		}
	}
	Eigen::EigenSolver<MatrixXd> es(m);
	cout << "Eigen Values: " << endl;
	cout << fixed << es.pseudoEigenvalueMatrix() << endl << endl;
	//Step 3: Find Eigen Vector
	cout << "Eigen Vectors: " << endl;
	cout << fixed << es.pseudoEigenvectors() << endl << endl;
	//Step 4: Find the other Matrix
	// U = A * V * sigma^T
	MatrixXd eigenVectors(columns, columns);
	MatrixXd eigenValues(columns, columns);
	eigenVectors = es.pseudoEigenvectors();
	eigenValues = es.pseudoEigenvalueMatrix();
	double usedMatrix[100][100];
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			usedMatrix[i][j] = eigenVectors(i, j);
		}
	}
	double resMatrix2[100][100];
	matrixMultiplication(matrix, usedMatrix, resMatrix2, rows, columns);
	cout << "A * V: " << endl;
	displayMatrix(resMatrix2, rows, rows);
	cout << endl;
	double sigmaMatrix[100][100];
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sigmaMatrix[i][j] = sqrt(eigenValues(i, j));
		}
	}
	cout << "Sigma Matrix: " << endl;
	displayMatrix(sigmaMatrix, columns, columns);
	cout << endl;
	double transposeSigmaMatrix[100][100];
	Transpose(sigmaMatrix, transposeSigmaMatrix, columns, columns);
	double finalResMatrix[100][100];
	matrixMultiplication(resMatrix2, sigmaMatrix, finalResMatrix, rows, rows);
	cout << "U: " << endl;
	displayMatrix(finalResMatrix, rows, columns);
}
void displayMatrix(double matrix[100][100], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void Transpose(double matrix[100][100], double transposeMatrix[100][100], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			transposeMatrix[j][i] = matrix[i][j];
		}
	}
}
//return a square matrix with rows = columns = rows of matrix A
void matrixMultiplication(double matrixA[100][100], double matrixB[100][100], double resMatrix[100][100], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			resMatrix[i][j] = 0;
			for (int k = 0; k < columns; k++)
			{
				resMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}