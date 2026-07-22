//MAINATA I NA SHIBANATA ZADACHA

#include <iostream>
#include <cmath> 

int getLength(long number) {
    number = std::abs(number);
    if (number == 0) {
        return 1;
    }

    int len = 0;
    while (number != 0) {
        len++;
        number /= 10;
    }

    return len;
}

bool checkNum(long number) {
    number = std::abs(number); 
    int length = getLength(number);

    
    if (length <= 2) {
        return true;
    }

    int* numElements = new int[length];
    int* numElementsSkip = new int[length - 1];

    long temp = number;
    for (size_t i = 0; i < length; i++) {
        numElements[length - i - 1] = temp % 10;
        temp /= 10;
    }

    for (size_t skipIndex = 0; skipIndex < length; skipIndex++) {
        bool isDescending = true;
        bool isAscending = true;

        int index = 0;

        for (size_t i = 0; i < length; i++) {
            if (i == skipIndex) {
                continue;
            }
            numElementsSkip[index++] = numElements[i];
        }

        for (size_t j = 0; j < length - 2; j++) {
            if (numElementsSkip[j] > numElementsSkip[j + 1]) {
                isAscending = false;
            }

            if (numElementsSkip[j] < numElementsSkip[j + 1]) {
                isDescending = false;
            }
        }

        if (isDescending || isAscending) {
            delete[] numElements;
            delete[] numElementsSkip;

            return true;
        }
    }

    delete[] numElements;
    delete[] numElementsSkip;

    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << checkNum(1324) << std::endl;  // true
    std::cout << checkNum(5412) << std::endl;  // true
    std::cout << checkNum(15243) << std::endl; // false
    std::cout << checkNum(12345) << std::endl; // true
    std::cout << checkNum(97531) << std::endl; // true
    std::cout << checkNum(12121) << std::endl; // false
    std::cout << checkNum(42) << std::endl;    // true
    std::cout << checkNum(-1324) << std::endl; // true
    std::cout << checkNum(0) << std::endl;     // true
    std::cout << checkNum(7) << std::endl;     // true
}
