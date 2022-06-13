#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void out(double P[][100])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << setprecision(4) << P[i][j] << "\t";
        }
        cout << endl;
    }
}
void makeIdentity(double A[100][100])
{
    for(int i = 0; i < 3; i++)
    {
        A[i][i] = 1;
        for(int j = 0; j < 3; j++)
        {
            if(i!=j) 
                A[i][j] = 0;
        }
    }
}
void assign(double A[100][100], double B[100][100])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            B[i][j] = A[i][j];
        }
    }
}
void matrixMultiply(double A[100][100], double B[100][100])
{
    double C[100][100];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
        
    }
    assign(C,A);
}

void matrixExponent(double A[100][100], double B[100][100], int n)
{
    if(n == 0)
    {
        makeIdentity(B);
        return;
    }
    if(n == 1)
    {
        assign(A,B);
        return;
    }
    matrixExponent(A,B,n/2);
    matrixMultiply(B,B);
    if(n % 2 != 0) matrixMultiply(B,A);
}
int main()
{
    int power;
    double P[100][100];
    cin >> power;
    ifstream myReadFile("input.txt");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            myReadFile >> P[i][j];
        }
    }
    double B[100][100];
    matrixExponent(P, B, power);
    out(B);
}