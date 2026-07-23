//MRAZQ BROINI SISTEMI!!!!

#include <iostream>

const int LETTER_DIFF = 'a' - 'A';

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

char toUpper(char c) {
    return c - LETTER_DIFF;
}

int charToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return 0;
}

int getLength(const char* input) {

    if (input == nullptr) {
        return 0;
    }

    int len = 0;

    while (*input != '\0') {
        len++;
        input++;
    }

    return len;
}

int convert(const char* input, int k) {
    if (input == nullptr) {
        return -1;
    }

    if (!(k >= 2 && k <= 36)) {
        return -1;
    }

    int length = getLength(input);
    int index = 0;
    char* upperCapsArr = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        if (isLower(input[i])) {
            upperCapsArr[index++] = toUpper(input[i]);
            continue;
        }

        upperCapsArr[index++] = input[i];
    }

    upperCapsArr[index] = '\0';

    int multiplier = 1;
    int result = 0;

    for (size_t i = 0; i < length; i++)
    {
        result += charToNum(upperCapsArr[length - 1 - i]) * multiplier;
        multiplier *= k;
    }

    delete[] upperCapsArr;

    return result;
}

int main() {
   
    std::cout << convert("101", 2) << " (5)" << std::endl;
    std::cout << convert("1A", 16) << " (26)" << std::endl;
    std::cout << convert("1a", 16) << " (26)" << std::endl;
    std::cout << convert("Z", 36) << " (35)" << std::endl;

    return 0;
}
