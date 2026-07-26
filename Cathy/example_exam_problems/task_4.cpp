#include <iostream>
using namespace std;
int sumAboveDiagonal(int** matrix, int n);

int main()
{
    int n = 3;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    // Запълване на матрицата:
    //  1  2  3
    //  4  5  6
    //  7  8  9
    int val = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = val++;
        }
    }
    cout << "Sum: " << sumAboveDiagonal(matrix, n)
        << " (Expected: 11)" << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int sumAboveDiagonal(int** matrix, int n)
{
    int sum = 0;
    if (matrix == nullptr || n <= 0)
    {
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            sum = sum + matrix[i][j];
        }
    }
    return sum;
}
