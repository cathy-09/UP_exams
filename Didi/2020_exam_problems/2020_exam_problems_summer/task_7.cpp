#include <iostream>

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

long convertNumber(char* num) {

    if (num == nullptr || *num == '\0') {
        return -1;
    }

    long sum = 0;

    while (*num != '\0') {
        if (!isDigit(*num)) {
            return -1;
        }

        int ascii = *num;
        sum += ascii;

        num++;
    }

    return sum;
}
 
int main() {
    // Test Case 1: Valid positive number
    char test1[] = "123";
    std::cout << "Test 1 (\"123\"): " << convertNumber(test1)
        << " | Expected: 150" << std::endl;

    // Test Case 2: Valid single digit
    char test2[] = "0";
    std::cout << "Test 2 (\"0\"): " << convertNumber(test2)
        << " | Expected: 48" << std::endl;

    // Test Case 3: Invalid number with letters
    char test3[] = "123a5";
    std::cout << "Test 3 (\"123a5\"): " << convertNumber(test3)
        << " | Expected: -1" << std::endl;

    // Test Case 4: Invalid number with punctuation
    char test4[] = "12.3";
    std::cout << "Test 4 (\"12.3\"): " << convertNumber(test4)
        << " | Expected: -1" << std::endl;

    // Test Case 5: Invalid number with negative sign
    char test5[] = "-123";
    std::cout << "Test 5 (\"-123\"): " << convertNumber(test5)
        << " | Expected: -1" << std::endl;

    // Test Case 6: Invalid empty string
    char test6[] = "";
    std::cout << "Test 6 (\"\"): " << convertNumber(test6)
        << " | Expected: -1 (or 0, depending on edge case implementation)" << std::endl;

    return 0;
}
