#include <iostream>

int* newArr(int* arr, int len) {

	if (arr == nullptr || len <= 0) {
		return nullptr;
	}

	int sum = 0;
	int counter = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] % 2 == 0) {
			counter++;
		}

		sum += arr[i];
	}

	int average = sum / len;

	int* result = new int[counter];
	int index = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] % 2 == 0) {
			result[index++] = arr[i] + average;
		}
	}

	return result;
}

int main() {
    std::cout << "--- Test 1: Given Example ---" << std::endl;
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int len1 = 8;
    int* res1 = newArr(arr1, len1);

    std::cout << "Original array: 1 2 3 4 5 6 7 8" << std::endl;
    std::cout << "Expected output: 6 8 10 12" << std::endl;
    std::cout << "Actual output:   ";
    // We know there are exactly 4 even numbers in the first test
    for (int i = 0; i < 4; ++i) {
        std::cout << res1[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res1;

    std::cout << "--- Test 2: All Even Numbers ---" << std::endl;
    int arr2[] = { 2, 4, 6 }; // Average is 4 (12 / 3)
    int len2 = 3;
    int* res2 = newArr(arr2, len2);

    std::cout << "Original array: 2 4 6" << std::endl;
    std::cout << "Expected output: 6 8 10" << std::endl;
    std::cout << "Actual output:   ";
    // We know there are exactly 3 even numbers in this test
    for (int i = 0; i < 3; ++i) {
        std::cout << res2[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res2;

    std::cout << "--- Test 3: With Negative Numbers ---" << std::endl;
    int arr3[] = { -2, 1, 3, 6 }; // Average is 2 (8 / 4)
    int len3 = 4;
    int* res3 = newArr(arr3, len3);

    std::cout << "Original array: -2 1 3 6" << std::endl;
    std::cout << "Expected output: 0 8" << std::endl;
    std::cout << "Actual output:   ";
    // We know there are exactly 2 even numbers in this test
    for (int i = 0; i < 2; ++i) {
        std::cout << res3[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res3;

    return 0;
}
