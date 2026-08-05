#include <iostream>

const int DIFF = 'a' - 'A';

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

char toLower(char c) {
    if (!isUpper(c)) return c;

    return c + DIFF;
}

char toUpper(char c) {
    if (!isLower(c)) return c;

    return c - DIFF;
}

void Revert(char input[]) {

    if (input == nullptr || *input == '\0') {
        return;
    }

    while (*input != '\0') {
        if (isLower(*input)) {
            *input = toUpper(*input);
        }
        else if (isUpper(*input)) {
            *input = toLower(*input);
        }

        input++;
    }
}

int main() {
    char text[] = "Test String 123!";

    std::cout << "Before: " << text << std::endl;
    Revert(text);
    std::cout << "After:  " << text << std::endl;

    return 0;
}
