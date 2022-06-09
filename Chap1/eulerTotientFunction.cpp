#include <iostream>
using namespace std;
long gcd(long theFirstNumber, long theSecondNumber);
int eulerTotientFunction(long number);
int main()
{
    long number;
    cin >> number;
    cout << eulerTotientFunction(number) << endl;
}
long gcd(long theFirstNumber, long theSecondNumber)
{
    if (theFirstNumber == 0 || theSecondNumber == 0)
    {
        return 0;
    }
    while (theFirstNumber != theSecondNumber)
    {
        if (theFirstNumber > theSecondNumber)
        {
            theFirstNumber -= theSecondNumber;
        }
        else
        {
            theSecondNumber -= theFirstNumber;
        }
    }
    return theFirstNumber;
}
int eulerTotientFunction(long number)
{
    int result = 0;
    for (int i = 1; i < number; i++)
    {
        if (gcd(i, number) == 1)
            result++;
    }
    return result;
}
