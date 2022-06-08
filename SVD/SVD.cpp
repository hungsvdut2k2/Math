#include <iostream>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;
void Tranpose(double matrix[100][100], double transposeMatrix[100][100], int n);
void MatrixMultiplication(double matrixA[100][100], double matrixB[100][100], int n);
void displayMatrix(double matrix[100][100], int n);
int main()
{
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
	//SVD can be used for rectangular matrix
	//so at the first step, we need to mutiply A with A^T to form a square matrix
	//Step 1; Calculate A * A^T
	double matrix[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = m(i, j);
		}
	}
	double transposeMatrix[100][100];
	Tranpose(matrix, transposeMatrix, n);
	double resMatrix[100][100];
	MatrixMultiplication(matrix, transposeMatrix, resMatrix, n);
	displayMatrix(resMatrix, n);
}
void Tranpose(double matrix[100][100], double transposeMatrix[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			transposeMatrix[i][j] = matrix[j][i];
		}
	}
}
void MatrixMultiplication(double matrixA[100][100], double matrixB[100][100], double resMatrix[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			resMatrix[i][j] = 0;

			for (int k = 0; k < n; k++)
			{
				resMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
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