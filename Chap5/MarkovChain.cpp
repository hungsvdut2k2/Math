#include <iostream>
#include <fstream>
using namespace std;
double a[3][3];
void matrixMultiply(double res[100][100])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                res[i][j] += a[i][k] * a[k][j];
            }
        }
        
    }
}
void matrixExponent(int power, double res[100][100])
{
    for (int i = 0; i < power; i++)
    {
        matrixMultiply(res);
    }
}
int main()
{
    int power;
    double res[100][100];
    cin >> power;
    ifstream myReadFile("input.txt");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            myReadFile >> a[i][j];
        }
    }
    matrixExponent(power, res);
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}