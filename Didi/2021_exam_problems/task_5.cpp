#include <iostream>

int** splitArr(int* arr, int M) {

	if (arr == nullptr || M <= 0) {
		return nullptr;
	}

    int** result = new int* [M];
	int sum = 0;

	for (size_t i = 0; i < M; i++)
	{
		sum += arr[i];
		result[i] = new int[2];
	}

	int average = sum / M;

	for (size_t i = 0; i < M; i++)
	{
		result[i][0] = arr[i];
		result[i][1] = average;
	}

    return result;
}

int main()
{
    // Test 1: From the example
    int arr1[] = { 1, 7, 4, 11, 23, 15, 12, 21 };
    int M1 = 8;
    int** res1 = splitArr(arr1, M1);

    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: { {1, 11}, {7, 11}, {4, 11}, {11, 11}, {23, 11}, {15, 11}, {12, 11}, {21, 11} }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < M1; i++)
    {
        std::cout << "{" << res1[i][0] << ", " << res1[i][1] << "}";
        if (i < M1 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl << std::endl;

    // Test 2: Small array with positive numbers
    int arr2[] = { 10, 20, 30 };
    int M2 = 3;
    int** res2 = splitArr(arr2, M2);

    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: { {10, 20}, {20, 20}, {30, 20} }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < M2; i++)
    {
        std::cout << "{" << res2[i][0] << ", " << res2[i][1] << "}";
        if (i < M2 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl << std::endl;

    // Test 3: Array with negative numbers
    int arr3[] = { -5, 5, 10, -10 };
    int M3 = 4;
    int** res3 = splitArr(arr3, M3);

    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: { {-5, 0}, {5, 0}, {10, 0}, {-10, 0} }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < M3; i++)
    {
        std::cout << "{" << res3[i][0] << ", " << res3[i][1] << "}";
        if (i < M3 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;

    // Free allocated memory
    for (int i = 0; i < M1; i++) delete[] res1[i];
    delete[] res1;

    for (int i = 0; i < M2; i++) delete[] res2[i];
    delete[] res2;

    for (int i = 0; i < M3; i++) delete[] res3[i];
    delete[] res3;

    return 0;
}
