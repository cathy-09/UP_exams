#include <iostream>

int** mergearrays(int* first, int* second, int m) {

    if (!first || !second || m <= 0) {
      return nullptr;
    }
  
    int** result = new int* [2];

    for (size_t i = 0; i < 2; i++)
    {
        result[i] = new int[m];
    }

    for (size_t index = 0; index < m; index++)
    {
        result[0][index] = first[index];
        result[1][index] = second[index];
    }

    return result;
}

// Helper function to print a 2D array with 2 rows and m columns
void print2DArray(int** arr, int m) {
    if (arr == nullptr) {
        std::cout << "NULL matrix\n";
        return;
    }

    std::cout << "{\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "  { ";
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << (j < m - 1 ? ", " : "");
        }
        std::cout << " }" << (i == 0 ? ",\n" : "\n");
    }
    std::cout << "}\n";
}

// Helper function to free dynamically allocated 2D array
void free2DArray(int** arr, int rows) {
    if (arr == nullptr) return;
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    // ==========================================
    // TEST 1: Example from the problem description
    // ==========================================
    std::cout << "=== TEST 1 ===" << std::endl;
    int A1[] = { 3, 5, 11, 2, 9 };
    int B1[] = { 1, 4, 32, 71, 5 };
    int m1 = 5;

    std::cout << "EXPECTED OUTPUT:" << std::endl;
    std::cout << "{\n  { 3, 5, 11, 2, 9 },\n  { 1, 4, 32, 71, 5 }\n}" << std::endl;

    std::cout << "\nACTUAL OUTPUT:" << std::endl;
    int** result1 = mergearrays(A1, B1, m1);
    print2DArray(result1, m1);
    free2DArray(result1, 2);

    std::cout << "\n----------------------------------------\n" << std::endl;

    // ==========================================
    // TEST 2: Array with negative numbers and m = 3
    // ==========================================
    std::cout << "=== TEST 2 ===" << std::endl;
    int A2[] = { -10, 0, 42 };
    int B2[] = { 100, -5, 7 };
    int m2 = 3;

    std::cout << "EXPECTED OUTPUT:" << std::endl;
    std::cout << "{\n  { -10, 0, 42 },\n  { 100, -5, 7 }\n}" << std::endl;

    std::cout << "\nACTUAL OUTPUT:" << std::endl;
    int** result2 = mergearrays(A2, B2, m2);
    print2DArray(result2, m2);
    free2DArray(result2, 2);

    return 0;
}
