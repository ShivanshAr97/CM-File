#include <iostream>
#include <math.h>
using namespace std;
double functionValue(double x, double y)
{
  double xSqr = pow(x, 2);
  double ysqr = pow(y, 2);
  return (ysqr - xSqr) / (ysqr + xSqr);
}
double calcValue(double x_0, double y_0, double x, double h)
{
  int times = (x - x_0) / h;
  for (int i = 0; i < times; i++)
  {
    double k_1 = h * functionValue(x_0, y_0);
    double k_2 = h * functionValue(x_0 + (h / 2), y_0 + (k_1 / 2));
    double k_3 = h * functionValue(x_0 + (h / 2), y_0 + (k_2 / 2));
    double k_4 = h * functionValue(x_0 + h, y_0 + k_3);
    double k = (1.0 / 6) * (k_1 + 2 * k_2 + 2 * k_3 + k_4);
    y_0 = y_0 + k;
    x_0 += h;
  }
  return y_0;
}
int main()
{
  double x_0;
  double y_0;
  double x;
  double h;
  cout << "\nEnter the value of x0 : ";
  cin >> x_0;
  cout << "Enter the value of y0 : ";
  cin >> y_0;
  cout << "\nEnter the value of x : ";
  cin >> x;
  cout << "\nEnter the value of h : ";
  cin >> h;
  cout << "\nSolution of differential equation at " << x << " is : " << calcValue(x_0, y_0, x, h);
  return 0;
}