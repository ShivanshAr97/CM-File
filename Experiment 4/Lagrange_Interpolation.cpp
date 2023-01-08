#include <iostream>

using namespace std;
int main()
{
    int n;
    cout<<"\nEnter no. of values: ";
    cin>>n;
    int x[n];
    int y[n];
    cout<<"\nEnter values of x: \n";
    for (int i = 0; i <n; i++)
    {
        cout<<"Enter value of x"<<i<<": ";
        cin>>x[i];
    }
    cout<<"\nEnter values of y: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter values of y"<<i<<": ";
        cin>>y[i];
    }
    int valueX;
    cout<<"\nEnter value of x for which f(x) is to be calculated: ";
    cin>>valueX;
    float value = 0;
    for (int i = 0; i < n; i++)
    {
        float temp = 1;
        temp *= y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                temp *= (valueX - x[j]);
                temp /= (x[i] - x[j]);
            }
            
        }
        value += temp;
    }
    cout<<"\nValue of f ("<<valueX<<") is: \n"<<value;

    return 0;
}