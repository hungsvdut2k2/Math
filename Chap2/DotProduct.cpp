#include <iostream>
using namespace std;
void inputVector(int size, int vector[]);
void outputVector(int size, int vector[]);
int dotProduct(int size, int theFirstVector[], int theSecondVector[]);
int main()
{
    int size;
    cin >> size;
    int theFirstVector[size];
    int theSecondVector[size];
    cout << "Input the first vector: " << endl;
    inputVector(size, theFirstVector);
    cout << "Input the second vector: " << endl;
    inputVector(size, theSecondVector);
    cout << "Dot Product: " << dotProduct(size, theFirstVector, theSecondVector) << endl;
}
void inputVector(int size, int vector[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> vector[i];
    }
}
void outputVector(int size, int vector[])
{
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " ";
    }
}
int dotProduct(int size, int theFirstVector[], int theSecondVector[])
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += theFirstVector[i] * theSecondVector[i];
    }
    return result;
}
