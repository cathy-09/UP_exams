#include <iostream>
using namespace std;
int* spiralRead(const int** matrix, size_t rows, size_t cols);

int main()
{
    size_t rows = 3, cols = 3;
    int** mat = new int* [rows];
    for (size_t i = 0; i < rows; i++) mat[i] = new int[cols];
    // 1 2 3
    // 4 5 6
    // 7 8 9
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;
    int* spiralRes = spiralRead((const int**)mat, rows, cols);
    cout << "(7 8 9 6 3 2 1 4 5): ";
    for (size_t i = 0; i < rows * cols; i++)
    {
        cout << spiralRes[i] << " ";
    }
    cout << endl;
    delete[] spiralRes;
    for (size_t i = 0; i < rows; i++) delete[] mat[i];
    delete[] mat;
}

int* spiralRead(const int** matrix, size_t rows, size_t cols)
{
    int* result = new int[rows * cols];
    size_t resultIndex = 0;
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    while (top <= bottom && left <= right)
    {
        for (size_t i = left; i <= right; i++)
        {
            result[resultIndex++] = matrix[bottom][i];
        }
        bottom--;
        if (left <= right && top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                result[resultIndex++] = matrix[i][right];
            }
            right--;
        }
        if (top <= bottom && left <= right)
        {
            for (size_t i = top; i <= bottom; i++)
            {
                result[resultIndex++] = matrix[top][i];
            }
            top++;
        }
        if (left <= right && top <= bottom)
        {
            for (int i = top; i <= bottom; i++)
            {
                result[resultIndex++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
