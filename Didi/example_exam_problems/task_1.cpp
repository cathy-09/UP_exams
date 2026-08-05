#include <iostream>

void mySwap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

void myBubbleSort(int* arr, int length) {
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				mySwap(arr[j], arr[j + 1]);
			}
		}
	}
}

int* mergeSortedArrays(int* first, int* second, int firstLen, int secondLen) {
    int* result = new int[firstLen + secondLen];

	int index = 0;
	for (size_t i = 0; i < firstLen; i++)
	{
		result[index++] = first[i];
	}

	for (size_t i = 0; i < secondLen; i++)
	{
		result[index++] = second[i];
	}

	myBubbleSort(result, firstLen + secondLen);

	return result;
}


// Helper function to print an array
void printArray(const int* arr, int size) {
    if (size == 0 || arr == nullptr) {
        std::cout << "[empty]";
    }
    else {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Standard arrays with duplicates
    int arr1_1[] = { 1, 3, 5, 5, 7 };
    int size1_1 = 5;
    int arr2_1[] = { 2, 5, 6, 8, 9 };
    int size2_1 = 5;

    std::cout << "--- Test Case 1: Standard with duplicates ---" << std::endl;
    std::cout << "Array 1: "; printArray(arr1_1, size1_1);
    std::cout << "Array 2: "; printArray(arr2_1, size2_1);

    int* result_1 = mergeSortedArrays(arr1_1, arr2_1, size1_1, size2_1);
    std::cout << "Result:  "; printArray(result_1, size1_1 + size2_1);
    std::cout << "Expected:1 2 3 5 5 5 6 7 8 9" << std::endl << std::endl;

    delete[] result_1; // Freeing the dynamically allocated memory


    // Test Case 2: Arrays of different sizes
    int arr1_2[] = { 10, 20, 30 };
    int size1_2 = 3;
    int arr2_2[] = { 5, 15, 25, 35, 45, 55 };
    int size2_2 = 6;

    std::cout << "--- Test Case 2: Different sizes ---" << std::endl;
    std::cout << "Array 1: "; printArray(arr1_2, size1_2);
    std::cout << "Array 2: "; printArray(arr2_2, size2_2);

    int* result_2 = mergeSortedArrays(arr1_2, arr2_2, size1_2, size2_2);
    std::cout << "Result:  "; printArray(result_2, size1_2 + size2_2);
    std::cout << "Expected:5 10 15 20 25 30 35 45 55" << std::endl << std::endl;

    delete[] result_2;


    // Test Case 3: One of the arrays is empty
    int arr1_3[] = { 1, 2, 3 };
    int size1_3 = 3;
    int arr2_3[1] = {}; // Empty array
    int size2_3 = 0;

    std::cout << "--- Test Case 3: One empty array ---" << std::endl;
    std::cout << "Array 1: "; printArray(arr1_3, size1_3);
    std::cout << "Array 2: "; printArray(arr2_3, size2_3);

    int* result_3 = mergeSortedArrays(arr1_3, arr2_3, size1_3, size2_3);
    std::cout << "Result:  "; printArray(result_3, size1_3 + size2_3);
    std::cout << "Expected:1 2 3" << std::endl << std::endl;

    delete[] result_3;


    // Test Case 4: Disjoint arrays (all elements of arr1 are smaller than arr2)
    int arr1_4[] = { 1, 2, 3 };
    int size1_4 = 3;
    int arr2_4[] = { 4, 5, 6, 7 };
    int size2_4 = 4;

    std::cout << "--- Test Case 4: Disjoint arrays ---" << std::endl;
    std::cout << "Array 1: "; printArray(arr1_4, size1_4);
    std::cout << "Array 2: "; printArray(arr2_4, size2_4);

    int* result_4 = mergeSortedArrays(arr1_4, arr2_4, size1_4, size2_4);
    std::cout << "Result:  "; printArray(result_4, size1_4 + size2_4);
    std::cout << "Expected:1 2 3 4 5 6 7" << std::endl << std::endl;

    delete[] result_4;

    return 0;
}
