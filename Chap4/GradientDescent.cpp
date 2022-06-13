//f(x) = ln(x^2) + (x-12) ^ 2 + x
#include<iostream>
#include <cmath>
using namespace std;
double derivative(double x);
double gradientDescent(double startPoint, double learningRate);
int main()
{
    double startPoint;
    double learningRate = 0.01;
    cin >> startPoint;
    double minimumPoint = gradientDescent(startPoint, learningRate);
    cout << minimumPoint << endl << derivative(minimumPoint) << endl;
}
double derivative(double x)
{
    return 2 / x + 2 * (x - 12) + 1;
}
double gradientDescent(double startPoint, double learningRate)
{
    double points[1000];
    points[0] = startPoint;
    int i;
    for (i = 1; i < 1000; i++)
    {
        points[i] = points[i - 1] - learningRate * derivative(points[i - 1]);
        if(fabs(derivative(points[i])) < pow(10, -3))
        {
            break;
        }
        cout << i << ": " << points[i] << endl;
    }
    return points[i];
}