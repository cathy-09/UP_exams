#include <iostream>
using namespace std;
double calculateMatrix(int** matr, int m);

int main()
{
    int m = 3;
    int** matr = new int* [m];
    for (int i = 0; i < m; i++) matr[i] = new int[m];

    //  1  2  3
    //  4  5  6
    //  7  8  9
    int val = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) matr[i][j] = val++;

    // Диагонали: (1+5+9) + (3+7) = 25 (5 се брои 1 път)
    cout << "3x3 matrix diag sum -> " << calculateMatrix(matr, m) << " (Expected: 25)" << endl;

    for (int i = 0; i < m; i++) delete[] matr[i];
    delete[] matr;
    cout << endl;
}

double calculateMatrix(int** matr, int m)
{
    int sum = 0;
    if (matr == nullptr || m <= 0)
    {
        return 0.0;
    }
    for (size_t i = 0; i < m; i++)
    {
        if (matr[i] == nullptr)
        {
            return 0.0;
        }
        sum = sum + matr[i][i];
        if (i != m - i - 1)
        {
            sum = sum + matr[i][m - i - 1];
        }
    }
    return sum;
}
