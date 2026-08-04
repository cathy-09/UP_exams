#include <iostream>

int findElement(long arr[], int l) {
    if (l < 3 || arr == nullptr) {
        return -1;
    }

    for (size_t i = l - 2; i >= 1; i--)
    {
        double average = (arr[i - 1] + arr[i + 1]) / 2.0;
        if (arr[i] > average) {
            return i;
        }
    }

    return -1;
}


int main() {
    // Test 1: Sample test from problem statement
    long arr1[] = { 2, 3, 17, 8, 1, 9 };
    std::cout << "Test 1 | Result: " << findElement(arr1, 6) << " | Expected: 2" << std::endl;

    // Test 2: Multiple matching elements (should return the rightmost index)
    // Index 1 (10 > (1+1)/2) and Index 4 (20 > (2+2)/2) both match.
    long arr2[] = { 1, 10, 1, 2, 20, 2 };
    std::cout << "Test 2 | Result: " << findElement(arr2, 6) << " | Expected: 4" << std::endl;

    // Test 3: No elements satisfy the condition
    long arr3[] = { 1, 2, 3, 4, 5 };
    std::cout << "Test 3 | Result: " << findElement(arr3, 5) << " | Expected: -1" << std::endl;

    // Test 4: Array size less than 3 (no inner elements)
    long arr4[] = { 10, 20 };
    std::cout << "Test 4 | Result: " << findElement(arr4, 2) << " | Expected: -1" << std::endl;

    // Test 5: Average with decimal part (5 > (3 + 6)/2.0 = 4.5)
    long arr5[] = { 3, 5, 6 };
    std::cout << "Test 5 | Result: " << findElement(arr5, 3) << " | Expected: 1" << std::endl;

    return 0;
}
