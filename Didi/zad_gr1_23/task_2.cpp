#include <iostream>

int getLength(long num) {
    if (num == 0) {
        return 0;
    }

    int len = 0;
    while (num != 0) {
        len++;
        num /= 10;
    }

    return len;
}

int* getDigitsArr(long num, int length) {
    int* digits = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        digits[length - 1 - i] = num - (num / 10) * 10;
        num /= 10;
    }

    return digits;
}

bool isItDevisibleBy3Skip(int digits[], int length, int skip) {

    int sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (i == skip) {
            continue;
        }
        sum += digits[i];
    }

    return sum == (sum / 3) * 3;
}

int checkNum(long N) {

    if (N < 0) {
        N = -N;
    }

    int length = getLength(N);

    if (length > 9) {
        return -1;
    }

    int* digits = getDigitsArr(N, length);

    for (size_t i = 0; i < length; i++)
    {
        if (isItDevisibleBy3Skip(digits, length, i)) {

            delete[] digits;
            return i + 1;
        }
    }

    delete[] digits;
    return 0;
}

int main()
{
    std::cout << "1000000000 -> " << checkNum(1000000000L) << " (-1)" << std::endl;
    std::cout << "-1000000000 -> " << checkNum(-1000000000L) << " (-1)" << std::endl;
    std::cout << "1234567890 -> " << checkNum(1234567890L) << " (-1)" << std::endl;
    std::cout << "345 -> " << checkNum(345) << " (1)" << std::endl;
    std::cout << "214 -> " << checkNum(214) << " (2)" << std::endl;
    std::cout << "123 -> " << checkNum(123) << " (3)" << std::endl;
    std::cout << "12 -> " << checkNum(12) << " (0)" << std::endl;
    std::cout << "104 -> " << checkNum(104) << " (0)" << std::endl;
    std::cout << "-214 -> " << checkNum(-214) << " (2)" << std::endl;
    std::cout << "-12 -> " << checkNum(-12) << " (0)" << std::endl;
    std::cout << "999999999 -> " << checkNum(999999999L) << " (1)" << std::endl;
}

