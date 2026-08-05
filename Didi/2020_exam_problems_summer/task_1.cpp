//Daje geminito se oburka ot uslovieto...

#include <iostream>

int largestSeq(int arr[], int N) {
    if (arr == nullptr || N <= 0) {
        return -1;
    }

    int maxCtr = 0;
    int maxSum = 0;
    int currentCtr = 0;
    int currentSum = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0) {
            currentCtr++;
            currentSum += arr[i];
        }
        else {
            if (currentCtr > maxCtr) {
                maxCtr = currentCtr;
                maxSum = currentSum;
            }

            currentCtr = 0;
            currentSum = 0;
        }
    }

    if (currentCtr > maxCtr) {
        maxCtr = currentCtr;
        maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    // Test 1: Given problem example (longest sequence has 3 elements: 12, 168, 144)
    int arr1[] = { 2, 4, 3, 11, 12, 168, 144, 5, 9, 62, 98, 1 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Test 1 | Output: " << largestSeq(arr1, n1) << " | Expected: 324\n";

    // Test 2: All odd numbers (no even sequences)
    int arr2[] = { 1, 3, 5, 7, 9 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Test 2 | Output: " << largestSeq(arr2, n2) << " | Expected: 0\n";

    // Test 3: Entire array consists of even numbers (length 4)
    int arr3[] = { 2, 4, 6, 8 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Test 3 | Output: " << largestSeq(arr3, n3) << " | Expected: 20\n";

    // Test 4: Longest count (3 elements: {4, 6, 8} sum=18) wins over higher single sum ({20})
    int arr4[] = { 10, 2, 1, 4, 6, 8, 3, 20 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "Test 4 | Output: " << largestSeq(arr4, n4) << " | Expected: 18\n";

    // Test 5: Longest sequence ({2, 4, 6} length 3, sum=12) wins over huge single elements ({1000}, {2000})
    int arr5[] = { 1000, 1, 2, 4, 6, 3, 2000 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    std::cout << "Test 5 | Output: " << largestSeq(arr5, n5) << " | Expected: 12\n";

    return 0;
}
