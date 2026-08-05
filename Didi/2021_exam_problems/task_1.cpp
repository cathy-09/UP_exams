#include <iostream>

long newNum(long num) {
    long result = 0;
    long multiplier = 1;

    while (num != 0) {
        int digit = num % 10;

        if (digit % 2 == 0) {
            result += digit * multiplier;
            multiplier *= 10;
        }

        num /= 10;
    }

    return result;
}

int main() {
    std::cout << "Test 1 (123456789): " << newNum(123456789) << " | Expected: 2468\n";
    std::cout << "Test 2 (5783932):   " << newNum(5783932) << " | Expected: 82\n";
    std::cout << "Test 3 (20468):     " << newNum(20468) << " | Expected: 20468\n";
    std::cout << "Test 4 (13579):     " << newNum(13579) << " | Expected: 0\n";
    std::cout << "Test 5 (6):         " << newNum(6) << " | Expected: 6\n";
    std::cout << "Test 6 (7):         " << newNum(7) << " | Expected: 0\n";
    std::cout << "Test 7 (0):         " << newNum(0) << " | Expected: 0\n";
    std::cout << "Test 8 (1034056):   " << newNum(1034056) << " | Expected: 406\n";
    std::cout << "Test 9 (-123456):   " << newNum(-123456) << " | Expected: -246 or 246\n";

    return 0;
}
