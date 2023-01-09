#include <iostream>
#include <math.h>
using namespace std;

double maxValueArray(double iden[], int order)
{
  double maxValue = iden[0];
  for (int i = 0; i < order; i++)
  {
    if (maxValue < iden[i])
      maxValue = iden[i];
  }
  return maxValue;
}

int continueLoop(double currentIden[], double prevIden[], int order)
{
  for (int i = 0; i < order; i++)
  {
    if (fabs(currentIden[i] - prevIden[i]) > .05)
      return 1;
  }
  return 0;
}
void copyArr(double source[], double destination[], int order)
{
  for (int i = 0; i < order; i++)
    destination[i] = source[i];
}
double multiMatrix(double *matrix, double currentIden[], int order)
{
  double tempIden[order];
  for (int i = 0; i < order; i++)
  {
    double temp = 0;
    for (int j = 0; j < order; j++)
      temp += currentIden[j] * (*(matrix + (i * order) + j));

    tempIden[i] = temp;
  }

  double maxValue = maxValueArray(tempIden, order);
  for (int i = 0; i < order; i++)
    currentIden[i] = tempIden[i] / maxValue;
  return maxValue;
}
int main()
{
  int order;
  cout << "\nEnter the order of the matrix : ";
  cin >> order;
  double matrix[order][order];
  double currentIden[order];
  double prevIden[order];
  int loop = 1;
  cout << "\nEnter the value of initial matrix A : " << endl;
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      cout << "Enter the value of A[" << i << "][" << j << "] : ";
      cin >> matrix[i][j];
    }
  }

  cout << "\nEnter the value of column matrix X : " << endl;
  for (int i = 0; i < order; i++)
  {
    cout << "Enter the value of X[" << i << "] : ";
    cin >> currentIden[i];
  }
  copyArr(currentIden, prevIden, order);
  double currentEigen = multiMatrix(&matrix[0][0], currentIden, order);

  while (continueLoop(currentIden, prevIden, order))
  {
    cout << "\nValue of eigen value at " << loop << " : " << currentEigen << endl;
    loop++;
    copyArr(currentIden, prevIden, order);
    currentEigen = multiMatrix(&matrix[0][0], currentIden, order);
  }
  cout << "Final eigen value : " << currentEigen << endl;
  return 0;
}