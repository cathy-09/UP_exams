#include <iostream>

double myAbs(double number) {
    return number > 0 ? number : -number;
}

int findMaxMin(const int* numbers, size_t size, int& minVal, int& maxVal) {

    if (size == 0) {
        return 0;
    }

    minVal = numbers[0];
    maxVal = numbers[0];
    int sum = numbers[0];

    for (size_t i = 1; i < size; i++)
    {
        sum += numbers[i];

        if (minVal > numbers[i]) {
            minVal = numbers[i];
        }

        if (maxVal < numbers[i]) {
            maxVal = numbers[i];
        }
    }

    double average = (double)sum / size;
    double minDiff = myAbs(numbers[0] - average);
    int closeset = numbers[0];

    for (size_t i = 1; i < size; i++)
    {
        double diff = myAbs(numbers[i] - average);

        if (diff < minDiff) {
            minDiff = diff;
            closeset = numbers[i];
        }
    }

    return closeset;
}

int main() {
    int arr1[] = { 10, 2, 8, 15, 5 };
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    int min1 = 0, max1 = 0;
    int res1 = findMaxMin(arr1, size1, min1, max1);

    std::cout << "--- Test 1 ---" << std::endl;
    std::cout << "Min: " << min1 << " (Expected: 2)" << std::endl;
    std::cout << "Max: " << max1 << " (Expected: 15)" << std::endl;
    std::cout << "Closest to avg: " << res1 << " (Expected: 8)" << std::endl;

    int arr2[] = { 1, 10, 20, 30 };
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    int min2 = 0, max2 = 0;
    int res2 = findMaxMin(arr2, size2, min2, max2);

    std::cout << "\n--- Test 2 ---" << std::endl;
    std::cout << "Min: " << min2 << " (Expected: 1)" << std::endl;
    std::cout << "Max: " << max2 << " (Expected: 30)" << std::endl;
    std::cout << "Closest to avg: " << res2 << " (Expected: 20)" << std::endl;

    int arr3[] = { -5, -15, -2, 0 };
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    int min3 = 0, max3 = 0;
    int res3 = findMaxMin(arr3, size3, min3, max3);

    std::cout << "\n--- Test 3 ---" << std::endl;
    std::cout << "Min: " << min3 << " (Expected: -15)" << std::endl;
    std::cout << "Max: " << max3 << " (Expected: 0)" << std::endl;
    std::cout << "Closest to avg: " << res3 << " (Expected: -5)" << std::endl;

    return 0;
}
