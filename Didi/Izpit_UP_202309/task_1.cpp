#include <iostream>
    
unsigned int getGCDtwo(unsigned int first, unsigned int second) {

    while (second != 0) {
        unsigned int temp = second;
        second = first % second;
        first = temp;
    }

    return first;
}

unsigned int getGCD(const unsigned int* numbers, size_t size) {
    unsigned int result = 0;

    if (size == 0 || numbers == nullptr) {
        return 0;
    }

    if (size == 1) {
        return numbers[0];
    }

    if (size == 2) {
        return getGCDtwo(numbers[0], numbers[1]);
    }

    for (size_t i = 0; i < size; i++)
    {
        result = getGCDtwo(result, numbers[i]);
    }

    return result;
}

int main() {
  
    unsigned int arr1[] = { 24, 36, 60, 48, 72 };
    std::cout << "Test 1: " << getGCD(arr1, 5) << " (Expected: 12)\n";

    unsigned int arr2[] = { 15, 8, 27 };
    std::cout << "Test 2: " << getGCD(arr2, 3) << " (Expected: 1)\n";

    unsigned int arr3[] = { 42 };
    std::cout << "Test 3: " << getGCD(arr3, 1) << " (Expected: 42)\n";

    unsigned int arr4[] = { 0, 0, 0 };
    std::cout << "Test 4: " << getGCD(arr4, 3) << " (Expected: 0)\n";

    return 0;
}
