#include <iostream>

int getLength(long number) {
    if (number == 0) {
        return 0;
    }

    int len = 0;

    while (number != 0) {
        len++;
        number /= 10;
    }

    return len;
}

bool checkNum(long number) {

    int length = getLength(number);
    int* numElements = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        numElements[length - i - 1] = number % 10;
        number /= 10;
    }

    for (size_t skipIndex = 0; skipIndex < length; skipIndex++)
    {
        bool isDescending = true;
        bool isAscending = true;

        for (size_t i = 0; i < length - 1; i++)
        {
            if (i == skipIndex) {
                continue;
            }

            isAscending = isAscending && (numElements[i] < numElements[i + 1]);
            isDescending = isDescending && (numElements[i] > numElements[i + 1]);
        }

        if (isAscending || isDescending) {
            return true;
        }

    }

    delete[] numElements;

    return false;
}

int main() {
    std::cout << std::boolalpha << checkNum(1324) << std::endl; //(true)
    std::cout << std::boolalpha << checkNum(5412) << std::endl; //(true)
    std::cout << std::boolalpha << checkNum(15243) << std::endl; //(false)
    std::cout << std::boolalpha << checkNum(12345) << std::endl;//(true)
    std::cout << std::boolalpha << checkNum(97531) << std::endl;//(true)
    std::cout << std::boolalpha << checkNum(12121) << std::endl;//(false)
    std::cout << std::boolalpha << checkNum(42) << std::endl;//(true)
    std::cout << std::boolalpha << checkNum(-1324) << std::endl;//(true)
}
