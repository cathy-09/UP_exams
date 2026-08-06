//Bah mama mu bilo lesno kato mu razberesh uslovieto

#include <iostream>

unsigned int myAbs(int num) {
    return num > 0 ? num : -num;
}

//returns -1 for incorrect data
//returns 0 for false
//returns 1 for true
int Check(const unsigned int* input, int N) {
    if (N < 3 || N > 100 || input == nullptr) {
        return -1;
    }

    int startDiff = 0;
    int endDiff = 0;
   
    for (size_t i = 0; i < N / 2; i++)
    {
        startDiff = myAbs(input[i] - input[i + 1]);
        endDiff = myAbs(input[N - i - 1] - input[N - i - 2]);

        if (startDiff != endDiff) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Test 1: Exposes the unsigned int subtraction issue
    // Mathematical differences: |2 - 5| = 3, |5 - 2| = 3 (Symmetrical)
    unsigned int arr1[] = { 2, 5, 2 };
    std::cout << "Test 1 (Underflow check)  - Expected: 1, Actual: " << Check(arr1, 3) << "\n\n";

    // Test 2: Exposes the out-of-bounds array access issue in the loop
    // Mathematical differences: 5, 3, 3, 5 (Symmetrical)
    unsigned int arr2[] = { 10, 15, 12, 9, 4 };
    std::cout << "Test 2 (Bounds check)     - Expected: 1, Actual: " << Check(arr2, 5) << "\n\n";

    // Test 3: Standard false case to verify basic logic
    // Mathematical differences: 2, 6, 2 (Not symmetrical)
    unsigned int arr3[] = { 10, 12, 15, 20 };
    std::cout << "Test 3 (False case check) - Expected: 0, Actual: " << Check(arr3, 4) << "\n\n";

    // Test 4: Edge case for validation
    std::cout << "Test 4 (Invalid N check)  - Expected: -1, Actual: " << Check(arr1, 2) << "\n";

    return 0;
}
