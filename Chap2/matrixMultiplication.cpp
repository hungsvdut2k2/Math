#include <iostream>
using namespace std;
void inputMatrix(int rows, int columns, int matrix[][100]);
void outputMatrix(int rows, int columns, int matrix[][100]);
void matrixMultiplication(int rowsOfFirstMatrix, int columnsOfFirstMatrix, int rowsOfSecondMatrix, int columnsOfSecondMatrix, int theFirstMatrix[][100], int theSecondMatrix[][100], int resultMatrix[][100]);
int main()
{
    int rowsOfFirstMatrix;
    int columnsOfFirstMatrix;
    int rowsOfSecondMatrix;
    int columnsOfSecondMatrix;
    int theFirstMatrix[1000][100];
    int theSecondMatrix[1000][100];
    int resultMatrix[1000][100];
    cin >> rowsOfFirstMatrix >> columnsOfFirstMatrix >> rowsOfSecondMatrix >> columnsOfSecondMatrix;
    cout << "Input for the first matrix" << endl;
    inputMatrix(rowsOfFirstMatrix, columnsOfFirstMatrix, theFirstMatrix);
    cout << "Input for the second matrix" << endl;
    inputMatrix(rowsOfSecondMatrix, columnsOfSecondMatrix, theSecondMatrix);
    matrixMultiplication(rowsOfFirstMatrix, columnsOfFirstMatrix, rowsOfSecondMatrix, columnsOfSecondMatrix, theFirstMatrix, theSecondMatrix ,resultMatrix);
    if(rowsOfFirstMatrix == columnsOfSecondMatrix) {
        outputMatrix(rowsOfSecondMatrix, columnsOfSecondMatrix, resultMatrix);
    }
    else {
        outputMatrix(rowsOfFirstMatrix, columnsOfSecondMatrix, resultMatrix);
    }
}
void inputMatrix(int rows, int columns, int matrix[][100]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }
}
void outputMatrix(int rows, int columns, int matrix[][100]) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void matrixMultiplication(int rowsOfFirstMatrix, int columnsOfFirstMatrix, int rowsOfSecondMatrix, int columnsOfSecondMatrix, int theFirstMatrix[][100], int theSecondMatrix[][100], int resultMatrix[][100]) {
    if(rowsOfFirstMatrix == columnsOfSecondMatrix) {
        for (int i = 0; i < rowsOfFirstMatrix; i++) {
            for (int j = 0; j < columnsOfSecondMatrix; j++) {
                int iterator = 0;
                int dotProduct = 1;
                while(iterator < rowsOfFirstMatrix) {
                    dotProduct += theFirstMatrix[i][iterator] * theSecondMatrix[iterator][j];
                }
                resultMatrix[i][j] = dotProduct;
            }
        }
    }
    else {
       for (int i = 0; i < rowsOfSecondMatrix; i++) {
            for (int j = 0; j < columnsOfFirstMatrix; j++) {
                int iterator = 0;
                int dotProduct = 1;
                while(iterator < columnsOfFirstMatrix) {
                    dotProduct += theFirstMatrix[iterator][j] * theSecondMatrix[i][iterator];
                }
                resultMatrix[i][j] = dotProduct;
            }
        } 
    }
}