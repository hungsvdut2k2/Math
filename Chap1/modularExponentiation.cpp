#include <iostream>
using namespace std;
long long recursiveMethod(long long number, long long work, long long modulo);
int main()
{
    long long number, work, modulo;
    cout << "Enter 3 numbers: ";
    cin >> number >> work >> modulo;
    cout << recursiveMethod(number, work, modulo) << endl;
}
long long recursiveMethod(long long number, long long work, long long modulo)
{
    if (work == 0)
        return 1;
    long long res = recursiveMethod(number, work / 2, modulo);
    if (work % 2 == 0)
    {
        return (res * res) % modulo;
    }
    else
    {
        return (res * res * number) % modulo;
    }
}