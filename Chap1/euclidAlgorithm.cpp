// giải thuật euclid
// dựa theo quy tắc nếu ta lấy hiệu của 1 số lớn hơn và số nhỏ hơn
// thì UCNN của 2 số vẫn không đổi
#include <iostream>
using namespace std;
long gcd(long theFirstNumber, long theSecondNumber);
int main()
{
    long theFirstNumber;
    long theSecondNumber;
    cin >> theFirstNumber >> theSecondNumber;
    cout << gcd(theFirstNumber, theSecondNumber) << endl;
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