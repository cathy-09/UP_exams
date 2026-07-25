#include <iostream>

double calculateMatrix(int** matr, int m) {

	if (m <= 0 || matr == nullptr) {
		return 0.0;
	}

    double sum = 0.0;

	for (size_t rows = 0; rows < m; rows++)
	{
		for (size_t cols = 0; cols < m; cols++)
		{

			if (rows == cols) {
				sum += matr[rows][cols];
			}

			if ((rows + cols) == m - 1) {

				if (rows == cols) continue;

				sum += matr[rows][cols];
			}
		}
	}

	return sum;
}

int main() {
   
    // --- Test 1: 1x1 Matrix ---
    std::cout << "=== Test 1: 1x1 Matrix ===" << std::endl;
    int m1 = 1;
    int** matr1 = new int* [m1];
    matr1[0] = new int[1] { 42 };

    std::cout << "Input Matrix:" << std::endl;
    std::cout << "  [ " << matr1[0][0] << " ]\n";
    std::cout << "Expected Output: 42" << std::endl;
    std::cout << "Actual Output:   " << calculateMatrix(matr1, m1) << std::endl << std::endl;

    delete[] matr1[0];
    delete[] matr1;

    // --- Test 2: 2x2 Matrix ---
    std::cout << "=== Test 2: 2x2 Matrix ===" << std::endl;
    int m2 = 2;
    int** matr2 = new int* [m2];
    matr2[0] = new int[2] { 1, 2 };
    matr2[1] = new int[2] { 3, 4 };

    std::cout << "Input Matrix:" << std::endl;
    for (int i = 0; i < m2; ++i) {
        std::cout << "  [ ";
        for (int j = 0; j < m2; ++j) {
            std::cout << matr2[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "Expected Output: 10 (Main: 1+4, Sec: 2+3)" << std::endl;
    std::cout << "Actual Output:   " << calculateMatrix(matr2, m2) << std::endl << std::endl;

    for (int i = 0; i < m2; ++i) delete[] matr2[i];
    delete[] matr2;

    // --- Test 3: 3x3 Matrix ---
    std::cout << "=== Test 3: 3x3 Matrix ===" << std::endl;
    int m3 = 3;
    int** matr3 = new int* [m3];
    matr3[0] = new int[3] { 1, 2, 3 };
    matr3[1] = new int[3] { 4, 5, 6 };
    matr3[2] = new int[3] { 7, 8, 9 };

    std::cout << "Input Matrix:" << std::endl;
    for (int i = 0; i < m3; ++i) {
        std::cout << "  [ ";
        for (int j = 0; j < m3; ++j) {
            std::cout << matr3[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "Expected Output: 25 (Main: 1+5+9, Sec: 3+7, Center 5 counted once)" << std::endl;
    std::cout << "Actual Output:   " << calculateMatrix(matr3, m3) << std::endl << std::endl;

    for (int i = 0; i < m3; ++i) delete[] matr3[i];
    delete[] matr3;

    // --- Test 4: 4x4 Matrix with Negative Values ---
    std::cout << "=== Test 4: 4x4 Matrix with Negative Values ===" << std::endl;
    int m4 = 4;
    int** matr4 = new int* [m4];
    matr4[0] = new int[4] {  5, 0, 0, -2 };
    matr4[1] = new int[4] {  0, 3, 1, 0 };
    matr4[2] = new int[4] {  0, -4, 2, 0 };
    matr4[3] = new int[4] { 10, 0, 0, 6 };

    std::cout << "Input Matrix:" << std::endl;
    for (int i = 0; i < m4; ++i) {
        std::cout << "  [ ";
        for (int j = 0; j < m4; ++j) {
            std::cout << matr4[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "Expected Output: 21 (Main: 5+3+2+6=16, Sec: -2+1-4+10=5)" << std::endl;
    std::cout << "Actual Output:   " << calculateMatrix(matr4, m4) << std::endl << std::endl;

    for (int i = 0; i < m4; ++i) delete[] matr4[i];
    delete[] matr4;

    return 0;
}
