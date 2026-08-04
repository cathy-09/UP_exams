//UJASNO....

#include <iostream>

void ConvertArr(long arr[], long S, long E) {

    if (S < 0 || S > E || E < 0 || S == E) {
        return;
    }


    while (S < E) {
        long temp = arr[S];
        arr[S] = arr[E];
        arr[E] = temp;

        S++;
        E--;
    }
}

void printArray(const long arr[], int size) {
    std::cout << "{";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "}\n";
}

int main() {
    // Test 1: Standard case from problem description
    {
        long arr[] = { 4, 5, 6, 7, 8, 9, 0, 1 };
        std::cout << "Test 1 (Standard case: S=2, E=5)\nBefore: ";
        printArray(arr, 8);
        ConvertArr(arr, 2, 5);
        std::cout << "After:  ";
        printArray(arr, 8);
        std::cout << "Expected: {4, 5, 9, 8, 7, 6, 0, 1}\n\n";
    }

    // Test 2: Invalid S (S < 0) -> Array should NOT change
    {
        long arr[] = { 1, 2, 3, 4, 5 };
        std::cout << "Test 2 (Invalid S: S=-1, E=3)\nBefore: ";
        printArray(arr, 5);
        ConvertArr(arr, -1, 3);
        std::cout << "After:  ";
        printArray(arr, 5);
        std::cout << "Expected: {1, 2, 3, 4, 5}\n\n";
    }

    // Test 3: Invalid range (S > E) -> Array should NOT change
    {
        long arr[] = { 1, 2, 3, 4, 5 };
        std::cout << "Test 3 (Invalid range: S=4, E=1)\nBefore: ";
        printArray(arr, 5);
        ConvertArr(arr, 4, 1);
        std::cout << "After:  ";
        printArray(arr, 5);
        std::cout << "Expected: {1, 2, 3, 4, 5}\n\n";
    }

    // Test 4: Single element range (S == E) -> Array should NOT change
    {
        long arr[] = { 10, 20, 30, 40 };
        std::cout << "Test 4 (Same indices: S=2, E=2)\nBefore: ";
        printArray(arr, 4);
        ConvertArr(arr, 2, 2);
        std::cout << "After:  ";
        printArray(arr, 4);
        std::cout << "Expected: {10, 20, 30, 40}\n\n";
    }

    // Test 5: Reversing the entire range (S=0 to E=size-1)
    {
        long arr[] = { 1, 2, 3, 4, 5 };
        std::cout << "Test 5 (Entire range: S=0, E=4)\nBefore: ";
        printArray(arr, 5);
        ConvertArr(arr, 0, 4);
        std::cout << "After:  ";
        printArray(arr, 5);
        std::cout << "Expected: {5, 4, 3, 2, 1}\n";
    }

    return 0;
}
