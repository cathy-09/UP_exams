//Mtazq size_t

#include <iostream>

int* revArr(int* arr, int len, int k) {

    if (arr == nullptr || len < 0 || k > len || k < 1) {
        return nullptr;
    }

    int* result = new int[len];

	int index = 0;
	for (int i = len - 1; i >= k - 1; i--)
	{
		result[index++] = arr[i];
	}

    for (int i = 0; i < k - 1; i++)
    {
        result[index++] = arr[i];
    }

    return result;
}

int main()
{
    // Test 1: From the example
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int len1 = 8;
    int k1 = 3;
    int* res1 = revArr(arr1, len1, k1);

    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: { 8, 7, 6, 5, 4, 3, 1, 2 }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < len1; i++)
    {
        std::cout << res1[i];
        if (i < len1 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl << std::endl;

    // Test 2: k = 1 (reverse the whole array)
    int arr2[] = { 10, 20, 30, 40 };
    int len2 = 4;
    int k2 = 1;
    int* res2 = revArr(arr2, len2, k2);

    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: { 40, 30, 20, 10 }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < len2; i++)
    {
        std::cout << res2[i];
        if (i < len2 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl << std::endl;

    // Test 3: k = len (reverse only the last element, then the rest)
    int arr3[] = { 5, 9, 2 };
    int len3 = 3;
    int k3 = 3;
    int* res3 = revArr(arr3, len3, k3);

    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: { 2, 5, 9 }" << std::endl;
    std::cout << "Output:   { ";
    for (int i = 0; i < len3; i++)
    {
        std::cout << res3[i];
        if (i < len3 - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;

    // Free allocated memory
    delete[] res1;
    delete[] res2;
    delete[] res3;

    return 0;
}
