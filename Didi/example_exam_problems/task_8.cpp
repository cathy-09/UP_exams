#include <iostream>

const char SEPARATOR = '.';
const int SEPARATOR_INDEX = 2;
const int LENGTH = 5;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int charToInt(char c) {
    
    if (!isDigit(c)) {
        return c;
    }

    return c - '0';
}

int getLen(char input[]) {

    if (input == nullptr || *input == '\0') {
        return 0;
    }

    int len = 0;

    while (*input != '\0') {
        len++;
        input++;
    }

    return len;
}

int getMaxDaysInMonth(int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return 29;
    }
}

bool CheckDate(char input[]) {

    if (input == nullptr || *input == '\0') {
        return false;
    }

    if (input[SEPARATOR_INDEX] != SEPARATOR) {
        return false;
    }

    int length = getLen(input);

    if (length != LENGTH) {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (i == SEPARATOR_INDEX) {
            continue;
        }

        if (!isDigit(input[i])) {
            return false;
        }
    }

    int days = charToInt(input[0]) * 10 + charToInt(input[1]);
    int month = charToInt(input[SEPARATOR_INDEX + 1]) * 10 + charToInt(input[SEPARATOR_INDEX + 2]);

    if (month < 1 || month > 12 || days < 1) {
        return false;
    }

    int maxDays = getMaxDaysInMonth(month);

    if (days > maxDays) {
        return false;
    }

    return true;

}

int main() {

    char t1[] = "31.01";
    char t2[] = "29.02";
    char t3[] = "31.04";
    char t4[] = "12.13";
    char t5[] = "32.05";
    char t6[] = "00.05";
    char t7[] = "15.5";
    char t8[] = "ab.cd";

    std::cout << t1 << " -> " << (CheckDate(t1) ? "Valid" : "Invalid") << "\n";
    std::cout << t2 << " -> " << (CheckDate(t2) ? "Valid" : "Invalid") << "\n";
    std::cout << t3 << " -> " << (CheckDate(t3) ? "Valid" : "Invalid") << "\n";
    std::cout << t4 << " -> " << (CheckDate(t4) ? "Valid" : "Invalid") << "\n";
    std::cout << t5 << " -> " << (CheckDate(t5) ? "Valid" : "Invalid") << "\n";
    std::cout << t6 << " -> " << (CheckDate(t6) ? "Valid" : "Invalid") << "\n";
    std::cout << t7 << " -> " << (CheckDate(t7) ? "Valid" : "Invalid") << "\n";
    std::cout << t8 << " -> " << (CheckDate(t8) ? "Valid" : "Invalid") << "\n";

    return 0;
}
