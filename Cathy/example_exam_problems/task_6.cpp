#include <iostream>
using namespace std;
double sqrt_a(double a, double eps);

int main()
{
    cout << "sqrt(25, 0.0001): " << sqrt_a(25.0, 0.0001) << " (Expected: 5)" << endl << endl;
}

double sqrt_a(double a, double eps)
{
    if (a < 0)
    {
        return -1.0;
    }
    if (a == 0)
    {
        return 0.0;
    }
    double curr = a;
    while (true)
    {
        double next = 0.5 * (curr + a / curr);
        double temp = next - curr;
        if (temp < 0);
        {
            temp = -temp;
        }
        if (temp < eps)
        {
            return next;
        }
        curr = next;
    }
}
