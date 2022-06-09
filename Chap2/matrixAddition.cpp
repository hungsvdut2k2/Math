#include <iostream>
using namespace std;
void inputMatrix(int rows, int columns, int matrix[][100]);
void outputMatrix(int rows, int columns, int matrix[][100]);
void matrixAddition(int rows, int columns, int theFirstMatrix[][100], int theSecondMatrix[][100]);
int main()
{
    int rows;
    int columns;
    int theFirstMatrix[1000][100];
    int theSecondMatrix[1000][100];
    cin >> rows >> columns;
    cout << "Input for the first matrix: " << endl;
    inputMatrix(rows, columns, theFirstMatrix);
    cout << "Input for the second matrix: " << endl;
    inputMatrix(rows, columns, theSecondMatrix);
    matrixAddition(rows, columns, theFirstMatrix, theSecondMatrix);
    cout << "The result matrix:" << endl;
    outputMatrix(rows, columns, theFirstMatrix);
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
void matrixAddition(int rows, int columns, int theFirstMatrix[][100], int theSecondMatrix[][100]) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            theFirstMatrix[i][j] += theSecondMatrix[i][j];
        }
    }
}