#include <iostream>

const int ARRAY_LENGTH = 10;
         
bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int charToNum(char c) {
    return c - '0';
}

int analyzeArray(const char* input) {

    bool inputNumbers[ARRAY_LENGTH] = { 0 };

    while (*input != '\0') {
        if (isNumber(*input)) {
            inputNumbers[charToNum(*input)] = true;
        }
        
        input++;
    }

    for (int i = ARRAY_LENGTH - 1; i >= 0; i--)
    {
        if (inputNumbers[i] == false) {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::cout << analyzeArray("12345678990w");
    std::cout << analyzeArray("12jioswq090w");
    std::cout << analyzeArray("000000000");
    std::cout << analyzeArray("736492");
    std::cout << analyzeArray("");
}
