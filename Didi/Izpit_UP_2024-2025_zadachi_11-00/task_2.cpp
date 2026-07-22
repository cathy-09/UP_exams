//NAPRAVI SI PO-QSNO USLOVIETO ALDI

#include <iostream>

const int NUM_COUNT = 3;

enum ErrorCode {
    INVALID_INPUT = -1,   
    NOT_THREE_DIGITS = -2,    
    NO_PALINDROME = -3       
};

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int charToNum(char c) {
    return c - '0';
}

int findNumber(const char* str) {
                 
    if (str == nullptr) {
        return INVALID_INPUT;
    }

    int digitCounter = 0;
    int digitArr[NUM_COUNT] = { 0 };
    int index = 0;

    while (*str != '\0') {
        if (!isDigit(*str)) {
            str++;
            continue;
        }

        digitCounter++;

        if (digitCounter > NUM_COUNT) {
            return NOT_THREE_DIGITS;
        }

        digitArr[index++] = charToNum(*str);

        str++;
    }

    if (digitCounter != NUM_COUNT) {
        return NOT_THREE_DIGITS;
    }

    if (digitArr[0] == digitArr[1] && digitArr[0] != 0) {
        return digitArr[0] * 100 + digitArr[2] * 10 + digitArr[1];
    }
    else if (digitArr[0] == digitArr[2] && digitArr[0] != 0) {
        return digitArr[0] * 100 + digitArr[1] * 10 + digitArr[2];
    }
    else if (digitArr[1] == digitArr[2] && digitArr[1] != 0) {
        return digitArr[1] * 100 + digitArr[0] * 10 + digitArr[2];
    }
    else {
        return NO_PALINDROME;
    }
}


int main() {
    std::cout << "Input: nullptr -> Result: " << findNumber(nullptr) << "\n";

    std::cout << "Input: \"\" -> Result: " << findNumber("") << "\n";
    std::cout << "Input: \"abc\" -> Result: " << findNumber("abc") << "\n";
    std::cout << "Input: \"a1b\" -> Result: " << findNumber("a1b") << "\n";
    std::cout << "Input: \"a1b2\" -> Result: " << findNumber("a1b2") << "\n";
    std::cout << "Input: \"a1b2c3d4\" -> Result: " << findNumber("a1b2c3d4") << "\n";

    std::cout << "Input: \"a1b2c3\" -> Result: " << findNumber("a1b2c3") << "\n";

    std::cout << "Input: \"a1b3c1\" -> Result: " << findNumber("a1b3c1") << "\n";
    std::cout << "Input: \"7a7b7\" -> Result: " << findNumber("7a7b7") << "\n";
    std::cout << "Input: \"0a5b5\" -> Result: " << findNumber("0a5b5") << "\n";
    std::cout << "Input: \"9a2b9\" -> Result: " << findNumber("9a2b9") << "\n";

    std::cout << "Input: \"0a0b5\" -> Result: " << findNumber("0a0b5") << "\n";

    return 0;
}
