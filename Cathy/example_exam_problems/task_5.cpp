#include <iostream>
using namespace std;
const int MAX_SIZE = 50;
void transposeMatrix(const int A[][MAX_SIZE], int n, int result[][MAX_SIZE]);

int main()
{
    int n = 3;
    int A[MAX_SIZE][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(A, n, transposed);
    cout << "Transponirana:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposed[i][j] << " ";
        }
        cout << "\n";
    }
}

void transposeMatrix(const int A[][MAX_SIZE], int n, int result[][MAX_SIZE])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            result[i][j] = A[j][i];
        }
    }
}
