#include <iostream>

using namespace std;
int main()
{
    int x[10], y[10], z[10];
    int n, f, k;
    int j = 1;
    int f1 = 1;
    int f2 = 0;

    cout << "No. of observations: ";
    cin >> n;
    cout << "Different values of x: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << "Corresponding values of y: ";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    f = y[1];
    cout << "Value of k: ";
    cin >> k;
    do
    {
        for (int i = 0; i < n; i++)
        {
            z[i] = (y[i + 1] - y[i]) / (y[i + j] - x[i]);
            y[i] = z[i];
        }
        for (int i = 0; i < j; i++)
        {
            f1 *= (k - x[i]);
        }

        f2 += (y[1] * f1);
        f1 = 1;
        n--;
        j++;
    } while (n != 1);
    f += f2;
    cout << "Function value at " << k << "i.e. f (" << k << " ):" << f;

    return 0;
}