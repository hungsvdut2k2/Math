// f(x) = ln(x^2) + (x-12) ^ 2 + x
#include <iostream>
#include <cmath>
using namespace std;
double f(double x);
double derivative(double x);
double GradientDescentMomentum(double startPoint, double alpha, double beta);
int main()
{
    double startPoint;
    double alpha = 0.01;
    double beta = 0.9;
    cin >> startPoint;
    cout << fixed << GradientDescentMomentum(startPoint, alpha, beta) << endl;
}
double f(double x)
{
    return log(pow(x, 2)) + pow((x - 12), 2) + x;
}
double derivative(double x)
{
    return 2 / x + 2 * (x - 12) + 1;
}
double GradientDescentMomentum(double startPoint, double alpha, double beta)
{
    double points[1000];
    double deltaX = 0;
    double newDeltaX;
    points[0] = startPoint;
    int i;
    for (i = 1; i < 1000; i++)
    {
        newDeltaX = deltaX * alpha - derivative(points[i - 1]);
        points[i] = points[i - 1] + alpha * newDeltaX - beta * derivative(points[i - 1]);
        deltaX = newDeltaX;
        if (fabs(derivative(points[i])) < pow(10, -3))
        {
            break;
        }
        cout << i << ": "<< points[i] << endl;
    }
    return points[i];
}