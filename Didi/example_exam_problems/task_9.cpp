#include <iostream>

int getLen(long num) {

    if (num == 0) {
        return 1;
    }

    int len = 0;

    while (num != 0) {
        len++;
        num /= 10;
    }

    return len;
}

int DigitPos(long num, int k) {

    if (k < 1) {
        return -1;
    }

    if (num < 0) {
        num = -num;
    }

    long copyNum = num;

    int length = getLen(num);

    if (k > length) {
        return -1;
    }

    int* digits = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        digits[length - i - 1] = copyNum % 10;
        copyNum /= 10;
    }
    
    int result = digits[k - 1];

    delete[] digits;

    return result;;
}


int main() {
    std::cout << "DigitPos(12345, 1)  | Expected: 1  | Actual: " << DigitPos(12345, 1) << std::endl;
    std::cout << "DigitPos(12345, 3)  | Expected: 3  | Actual: " << DigitPos(12345, 3) << std::endl;
    std::cout << "DigitPos(12345, 5)  | Expected: 5  | Actual: " << DigitPos(12345, 5) << std::endl;
    std::cout << "DigitPos(12345, 6)  | Expected: -1 | Actual: " << DigitPos(12345, 6) << std::endl;
    std::cout << "DigitPos(12345, 0)  | Expected: -1 | Actual: " << DigitPos(12345, 0) << std::endl;
    std::cout << "DigitPos(-9876, 2)  | Expected: 8  | Actual: " << DigitPos(-9876, 2) << std::endl;
    std::cout << "DigitPos(0, 1)      | Expected: 0  | Actual: " << DigitPos(0, 1) << std::endl;
    std::cout << "DigitPos(0, 2)      | Expected: -1 | Actual: " << DigitPos(0, 2) << std::endl;
    return 0;
}
