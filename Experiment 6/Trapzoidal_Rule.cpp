#include <bits/stdc++.h>

#define f(x) 1 / (1 + pow(x, 2))
using namespace std;
int main()
{
    float lower, upper, stepSize, k, integration = 0.0;
    int subInterval;

    cout << "Lower limit of integration: ";
    cin >> lower;
    cout << "Upper limit of integration: ";
    cin >> upper;
    cout << "Number of sub intervals: ";
    cin >> subInterval;

    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper);
    for (int i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        integration = integration + 2 * (f(k));
    }
    integration = integration * stepSize / 2;
    cout << "Answer is: " << integration;

    return 0;
}