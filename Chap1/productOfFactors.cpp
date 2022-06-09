// tích các ước số
// công thức n ^ (số ước số) / 2
#include <iostream>
#include <cmath>
using namespace std;
int numberOfFactors(long number);
long productOfFactors(long number);
int main()
{
    long number;
    cin >> number;
    cout << productOfFactors(number) << endl;
}
int numberOfFactors(long number)
{
    // cách làm là lấy n / các số nguyên tố bắt đầu từ 2
    // nhân số lần chia cho nhau -> kết quả
    long result = 1;
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
        }
        result *= (count + 1);
    }
    cout << "So cac uoc so: " << result << endl;
    return result;
}
long productOfFactors(long number)
{
    return pow(number, numberOfFactors(number) / 2);
}