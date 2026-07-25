#include <iostream>

bool AnalyzeArr(int arr[], int length) {
    if (arr == nullptr || length < 2) {
        return false;
    }

    int counter = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (counter >= 2) {
            return true;
        }

        if (arr[i] == i) { 
            counter++; 
        }
    }

    if (counter >= 2) {
        return true;
    }

    return false;
}

int main() {
    std::cout << std::boolalpha; // Prints boolean values as 'true' or 'false'

    // Test Case 1: Array with multiple fixed elements (at index 0, 1, 2)
    {
        int arr[] = { 0, 1, 2, 9, 8 };
        int length = 5;
        bool expected = true;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 1 (Multiple fixed elements):\n";
        std::cout << "  Input Array: [0, 1, 2, 9, 8]\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    // Test Case 2: Array with exactly two fixed elements (at index 1 and 3)
    {
        int arr[] = { 10, 1, 5, 3 };
        int length = 4;
        bool expected = true;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 2 (Exactly two fixed elements):\n";
        std::cout << "  Input Array: [10, 1, 5, 3]\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    // Test Case 3: Array with only one fixed element (at index 0)
    {
        int arr[] = { 0, 5, 8, 12 };
        int length = 4;
        bool expected = false;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 3 (Only one fixed element):\n";
        std::cout << "  Input Array: [0, 5, 8, 12]\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    // Test Case 4: Array with zero fixed elements
    {
        int arr[] = { 5, 4, 3, 2 };
        int length = 4;
        bool expected = false;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 4 (Zero fixed elements):\n";
        std::cout << "  Input Array: [5, 4, 3, 2]\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    // Test Case 5: Invalid length (length <= 0)
    {
        int arr[] = { 0, 1, 2 };
        int length = -1;
        bool expected = false;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 5 (Invalid length):\n";
        std::cout << "  Input Array: [0, 1, 2]\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    // Test Case 6: Null pointer
    {
        int* arr = nullptr;
        int length = 5;
        bool expected = false;
        bool actual = AnalyzeArr(arr, length);

        std::cout << "Test 6 (Null pointer):\n";
        std::cout << "  Input Array: nullptr\n";
        std::cout << "  Length: " << length << "\n";
        std::cout << "  Expected Output: " << expected << "\n";
        std::cout << "  Actual Output:   " << actual << "\n\n";
    }

    return 0;
}
