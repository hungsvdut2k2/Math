// tổng các ước số
#include <iostream>
#include <cmath>
using namespace std;
long sumOfFactors(long number);
int main()
{
    long number;
    cin >> number;
    cout << sumOfFactors(number) << endl;
}
long sumOfFactors(long number)
{
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
    return sum;
}