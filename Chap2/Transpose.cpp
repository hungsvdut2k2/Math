#include <iostream>
using namespace std;
void inputMatrix(int rows, int columns, int matrix[][100]);
void outputMatrix(int rows, int columns, int matrix[][100]);
void transpose(int rows, int columns, int matrix[][100], int resultMatrix[][100]);
int main() {
    int rows;
    int columns;
    cin >> rows >> columns;
    int matrix[rows][100];
    int resultMatrix[rows][100];
    cout << "Input matrix: " << endl;
    inputMatrix(rows, columns, matrix);
    transpose(rows, columns, matrix, resultMatrix);
    cout << "Transpose matrix: " << endl;
    outputMatrix(rows, columns, resultMatrix);
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
void transpose(int rows, int columns, int matrix[][100], int resultMatrix[][100]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            resultMatrix[i][j] = matrix[j][i];
        }
    }
}