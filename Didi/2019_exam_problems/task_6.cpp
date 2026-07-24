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

int NumCalc(long num, int k, int l) {

    if (num < 0) {
        num = -num;
    }

    if (num == 0) {
        if (k == l && k == 1) {
            return 0;
        }
        else {
            return -1;
        }
    }
   
    int length = getLength(num);

    if ((k <= 0 || k > length) || (l <= 0 || l > length)) {
        return -1;
    }

    int* digits = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        digits[length - i - 1] = num % 10;
        num /= 10;
    }

    int result = digits[k - 1] + digits[l - 1];

    delete[] digits;

    return result;
}

int main() {
     //Left-to-right 1-based indexing:
     //For num = 123456 -> 1st:1, 2nd:2, 3rd:3, 4th:4, 5th:5, 6th:6

    //Standard valid cases
    std::cout << "Input: num = 123456, k = 2, l = 4 | Expected: 6  | Actual: " << NumCalc(123456L, 2, 4) << "\n";
    std::cout << "Input: num = 987, k = 1, l = 2    | Expected: 17 | Actual: " << NumCalc(987L, 1, 2) << "\n";
    std::cout << "Input: num = 5, k = 1, l = 1      | Expected: 10 | Actual: " << NumCalc(5L, 1, 1) << "\n";
    std::cout << "Input: num = 0, k = 1, l = 1      | Expected: 0  | Actual: " << NumCalc(0L, 1, 1) << "\n";

    //Negative number case (ignoring the minus sign for digit counting)
    std::cout << "Input: num = -12345, k = 2, l = 3 | Expected: 5  | Actual: " << NumCalc(-12345L, 2, 3) << "\n";

    // Invalid input cases (k or l <= 0)
    std::cout << "Input: num = 12345, k = 0, l = 2  | Expected: -1 | Actual: " << NumCalc(12345L, 0, 2) << "\n";
    std::cout << "Input: num = 12345, k = 2, l = -1 | Expected: -1 | Actual: " << NumCalc(12345L, 2, -1) << "\n";

    // Out of bounds cases (k or l exceeds total digit count)
    std::cout << "Input: num = 12345, k = 6, l = 2  | Expected: -1 | Actual: " << NumCalc(12345L, 6, 2) << "\n";
    std::cout << "Input: num = 12345, k = 2, l = 10 | Expected: -1 | Actual: " << NumCalc(12345L, 2, 10) << "\n";

    return 0;
}
