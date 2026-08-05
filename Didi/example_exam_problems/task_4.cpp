#include <iostream>


double sumAboveMainDiagonal(int n, int** matrix) {
	if (matrix == nullptr || n <= 0) {
		return -1;
	}

	double sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i < j) {
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

// Helper function to allocate dynamic 2D array
int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

// Helper function to free dynamic 2D array memory
void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    // Test 1: 3x3 Matrix
    // Elements above main diagonal: 2, 3, 6 (Sum: 11)
    int n1 = 3;
    int** matrix1 = createMatrix(n1);
    int data1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n1; ++j)
            matrix1[i][j] = data1[i][j];

    std::cout << "Test 1 (3x3 matrix) - Sum above main diagonal: "
        << sumAboveMainDiagonal(n1, matrix1) << " (Expected: 11)\n";
    deleteMatrix(matrix1, n1);

    // Test 2: 4x4 Matrix
    // Elements above main diagonal: -1, 4, 2, 5, -3, 8 (Sum: 15)
    int n2 = 4;
    int** matrix2 = createMatrix(n2);
    int data2[4][4] = {
        {10, -1,  4,  2},
        { 0,  3,  5, -3},
        { 0,  0,  7,  8},
        { 0,  0,  0,  2}
    };
    for (int i = 0; i < n2; ++i)
        for (int j = 0; j < n2; ++j)
            matrix2[i][j] = data2[i][j];

    std::cout << "Test 2 (4x4 matrix) - Sum above main diagonal: "
        << sumAboveMainDiagonal(n2, matrix2) << " (Expected: 15)\n";
    deleteMatrix(matrix2, n2);

    // Test 3: 1x1 Matrix (Edge case: no elements above main diagonal)
    int n3 = 1;
    int** matrix3 = createMatrix(n3);
    matrix3[0][0] = 42;

    std::cout << "Test 3 (1x1 matrix) - Sum above main diagonal: "
        << sumAboveMainDiagonal(n3, matrix3) << " (Expected: 0)\n";
    deleteMatrix(matrix3, n3);

    return 0;
}
