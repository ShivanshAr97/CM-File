#include <iostream>
#include <cmath>
using namespace std;
float roundOff(float n, int dec);
float functionValue(float x);
int calculateM(float *a, float *b, float *m, int decimal);

int main()
{

    float temp, m1, m2, a = -1, b = -1;
    int decimal;
    cout << "Decimal places upto which you want check the accuracy of results:";
    cin >> decimal;
    float errorValue = .5 / pow(10, decimal);
    for (int i = 0; a == -1 || b == -1; i++)
    {
        temp = functionValue(i);

        if (temp < 0)
        {
            a = i;
        }
        else if (temp > 0)
        {
            b = i;
        }
        else
        {
            cout << "Root is found at : " << i;
            return 1;
        }
    }

    if (calculateM(&a, &b, &m1, decimal))
        return 0;
    if (calculateM(&a, &b, &m2, decimal))
        return 0;

    while (abs(m2 - m1) > errorValue)
    {
        m1 = m2;
        if (calculateM(&a, &b, &m2, decimal))
            return 0;
    }
    cout << "Root is" << roundOff(m2, decimal) << endl;
}
float functionValue(float x)
{
    return x * x * x - 4 * x - 9;
}
int calculateM(float *a, float *b, float *m, int decimal)
{
    *m = (*a + *b) / 2;
    float temp = functionValue(*m);
    if (temp > 0)
    {
        *b = *m;
    }
    else if (temp < 0)
    {
        *a = *m;
    }
    else
    {

        cout << "Root is found at : " << roundOff(*m, decimal);
        return -1;
    }
    return 0;
}
float roundOff(float n, int dec)
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