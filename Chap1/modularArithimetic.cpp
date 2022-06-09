#include <iostream>
using namespace std;
long long Power(long long x, long long y);
long long Sum(long long x, long long y, long long m);
long long Subtract(long long x, long long y, long long m);
long long Multiply(long long x, long long y, long long m);
long long Exponent(long long x, long long y, long long m);
int main()
{
    long long x, y, m;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;
    cout << "Enter m: ";
    cin >> m;
    cout << "Sum: " << Sum(x, y, m) << endl;
    cout << "Subtract: " << Subtract(x, y, m) << endl;
    cout << "Multiply: " << Multiply(x, y, m) << endl;
    cout << "Exponent: " << Exponent(x, y, m) << endl;
}
long long Power(long long x, long long y)
{
    int res = 1;
    for (int i = 0; i < y; i++)
    {
        res *= x;
    }
    return res;
}
long long Sum(long long x, long long y, long long m)
{
    return (x + y) % m;
}
long long Subtract(long long x, long long y, long long m)
{
    return (x - y) % m;
}
long long Multiply(long long x, long long y, long long m)
{
    return (x * y) % m;
}
long long Exponent(long long x, long long y, long long m)
{
    return Power(x, y) % m;
}