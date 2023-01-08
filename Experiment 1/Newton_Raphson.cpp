#include <iostream>
#include <cmath>
using namespace std;
double functionValue(double value);
double derivativeValue(double value);
void findRoot(double x_n, float error, int decimal);
double findX_n1(double x_n);
float roundOff(double n, int dec);
int main()
{
    double root;
    int error;
    cout << "Root:";
    cin >> root;
    cout << "Decimal upto which the root should be correct:";
    cin >> error;
    double errorValue = .5 * pow(10, -error);
    findRoot(root, errorValue, error);
}
double functionValue(double value)
{
    return value * value - 4 * value - 7;
}
double derivativeValue(double value)
{
    return 2 * value - 4;
}
double findX_n1(double x_n)
{

    double h = functionValue(x_n) / derivativeValue(x_n);
    return x_n - h;
}
void findRoot(double x_n, float error, int decimal)
{
    double x_n1 = findX_n1(x_n);

    while (abs(x_n1 - x_n) >= error)
    {
        x_n = x_n1;
        x_n1 = findX_n1(x_n);
    }
    cout << "The answer is :" << roundOff(x_n1, decimal);
}

float roundOff(double n, int dec)
{
    n *= pow(10, dec);
    float floatValue = n - trunc(n);
    if (floatValue > .5)
    {
        n++;
    }
    else if (floatValue == .5)
    {
        int lastDigit = int(n) % 10;
        if (lastDigit % 2 != 0)
        {
            n++;
        }
    }

    return ((int)n) / pow(10, dec);
}