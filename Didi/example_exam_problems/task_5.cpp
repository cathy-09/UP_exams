#include <iostream>

int** transposeMatrix(int n, int** matrix) {
    int** transposed = new int* [n];

    for (size_t i = 0; i < n; i++)
    {
        transposed[i] = new int[n];
    }


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            transposed[i][j] = matrix[j][i];
        }
    }

    return transposed;
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
    int n = 3;

    // Create and initialize the original matrix
    int** original = createMatrix(n);
    int value = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            original[i][j] = value++;
        }
    }

    // Print the original matrix
    std::cout << "Original Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << original[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Call the function to transpose
    int** transposed = transposeMatrix(n, original);

    // Print the transposed matrix
    std::cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Free memory for both matrices
    deleteMatrix(original, n);
    deleteMatrix(transposed, n);

    return 0;
}
