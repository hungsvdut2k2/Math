#include <iostream>
#include <cmath>
using namespace std;
long sumOfFactorsWithoutNumber(long number);
bool isPerfectNumber(long number);
int main()
{
    long number;
    cin >> number;
    isPerfectNumber(number) ? cout << "Perfect number" << endl : cout << "Not perfect number" << endl;
}
long sumOfFactorsWithoutNumber(long number)
{
    long temp = number;
    long sum = 1;
    for (int i = 2; i <= number; i++)
    {
        int count = 0;
        bool flag = false;
        if (number % i == 0)
        {
            cout << "Uoc: " << i << endl;
            flag = true;
        }
        while (number % i == 0)
        {
            number /= i;
            count++;
        }
        if (flag == true)
        {
            cout << "So mu: " << count << endl;
            long value1 = pow(i, count + 1) - 1;
            long value2 = i - 1;
            sum *= (value1 / value2);
        }
    }
    cout << "Tong cac uoc so khong tinh n: " << sum - temp << endl;
    return sum - temp;
}
bool isPerfectNumber(long number)
{
    return number == sumOfFactorsWithoutNumber(number) ? true : false;
}