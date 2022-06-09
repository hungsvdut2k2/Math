// sàng nguyên tố eratosthenes
#include <iostream>
using namespace std;
void sieveOfEratosthenes(long number);
int main()
{
    long number;
    cin >> number;
    sieveOfEratosthenes(number);
}
void sieveOfEratosthenes(long number)
{
    // mảng đánh dấu các số nguyên tố
    bool markers[number + 1];
    for (int i = 1; i <= number; i++)
    {
        // gán tất cả giá trị từ 1 -> n == true
        markers[i] = true;
    }
    // vòng lặp chạy từ 2 -> sqrt(n)
    for (int i = 2; i * i <= number; i++)
    {
        if (markers[i] == true)
        {
            // nếu i là số nguyên tố thì
            // tất cả các số có ước là i đều không phải số nguyên tố
            cout << "cac so duoc danh dau la uoc cua " << i << ": ";
            for (int j = 2; i * j <= number; j++)
            {
                markers[i * j] = false;

                cout << i * j << " ";
            }
            cout << endl;
        }
    }
    cout << "Cac so nguyen to: " << endl;
    // in ra kết quả là các số nguyên tố từ 1 -> n
    for (int i = 2; i <= number; i++)
    {
        if (markers[i] == true)
        {
            cout << i << " ";
        }
    }
}