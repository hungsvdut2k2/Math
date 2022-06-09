#include <iostream>
using namespace std;
int modularInverse(int m1, int m2);
void chineseRemainderTheorem(int b1, int b2, int b3, int m1, int m2, int m3);
int main()
{
    int b1;
    int b2;
    int b3;
    int m1;
    int m2;
    int m3;
    cin >> b1 >> b2 >> b3;
    cin >> m1 >> m2 >> m3;
    chineseRemainderTheorem(b1, b2, b3, m1, m2, m3);
}
int modularInverse(int m1, int m2)
{
    int result = 1;
    while (true)
    {
        if (((m1 * result) - 1) % m2 == 0)
        {
            break;
        }
        else
        {
            result++;
        }
    }
    return result;
}
void chineseRemainderTheorem(int b1, int b2, int b3, int m1, int m2, int m3)
{
    int n = m1 * m2 * m3;
    int n1 = n / m1;
    int n2 = n / m2;
    int n3 = n / m3;
    int x1 = modularInverse(n1, m1);
    int x2 = modularInverse(n2, m2);
    int x3 = modularInverse(n3, m3);
    int result = (b1 * n1 * x1) + (b2 * n2 * x2) + (b3 * n3 * x3);
    int afterResult = result - (n * (result / n));
    cout << "Result: " << result << " mod " << n << endl;
    cout << "Result after reduce: " << afterResult << " mod " << n << endl;
}