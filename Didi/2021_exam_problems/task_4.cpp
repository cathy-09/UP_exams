#include <iostream>

int* mergeArr(int* arr1, int* arr2, int len) {
    int* result = new int[len];

    for (size_t i = 0; i < len; i++)
    {
        bool isFound = false;

        for (size_t j = 0; j < len; j++)
        {
            if (arr2[j] > arr1[i]) {
                result[i] = j;
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            result[i] = -1;
        }
    }


    return result;
}

int main() {
    // ---------------------------------------------------------
    // Test 1: First example from the requirements
    // ---------------------------------------------------------
    int arr1_test1[] = { 1, 11, 3, 99, 5 };
    int arr2_test1[] = { 4, 2, 23, 0, 7 };
    int len_test1 = 5;

    int* result1 = mergeArr(arr1_test1, arr2_test1, len_test1);

    std::cout << "--- Test 1: First Example ---" << std::endl;
    std::cout << "Expected output: 0 2 0 -1 2" << std::endl;
    std::cout << "Actual output:   ";
    for (int i = 0; i < len_test1; ++i) {
        std::cout << result1[i] << " ";
    }
    std::cout << "\n\n";
    delete[] result1;

    // ---------------------------------------------------------
    // Test 2: Second example from the requirements
    // ---------------------------------------------------------
    int arr1_test2[] = { 22, 5, 17, 8, 90, 7, 12 };
    int arr2_test2[] = { 6, 9, 18, 7, 1, 2, 3 };
    int len_test2 = 7;

    int* result2 = mergeArr(arr1_test2, arr2_test2, len_test2);

    std::cout << "--- Test 2: Second Example ---" << std::endl;
    std::cout << "Expected output: -1 0 2 1 -1 1 2" << std::endl;
    std::cout << "Actual output:   ";
    for (int i = 0; i < len_test2; ++i) {
        std::cout << result2[i] << " ";
    }
    std::cout << "\n\n";
    delete[] result2;

    // ---------------------------------------------------------
    // Test 3: Edge Case - No greater elements in arr2
    // ---------------------------------------------------------
    int arr1_test3[] = { 50, 60, 70 };
    int arr2_test3[] = { 10, 20, 30 };
    int len_test3 = 3;

    int* result3 = mergeArr(arr1_test3, arr2_test3, len_test3);

    std::cout << "--- Test 3: No greater elements ---" << std::endl;
    std::cout << "Expected output: -1 -1 -1" << std::endl;
    std::cout << "Actual output:   ";
    for (int i = 0; i < len_test3; ++i) {
        std::cout << result3[i] << " ";
    }
    std::cout << "\n\n";
    delete[] result3;

    // ---------------------------------------------------------
    // Test 4: Edge Case - First element in arr2 is always greater
    // ---------------------------------------------------------
    int arr1_test4[] = { 1, 2, 3 };
    int arr2_test4[] = { 100, 5, 10 };
    int len_test4 = 3;

    int* result4 = mergeArr(arr1_test4, arr2_test4, len_test4);

    std::cout << "--- Test 4: First element is always greater ---" << std::endl;
    std::cout << "Expected output: 0 0 0" << std::endl;
    std::cout << "Actual output:   ";
    for (int i = 0; i < len_test4; ++i) {
        std::cout << result4[i] << " ";
    }
    std::cout << "\n";
    delete[] result4;

    return 0;
}
