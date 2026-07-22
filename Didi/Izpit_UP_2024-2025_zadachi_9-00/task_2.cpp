#include <iostream>

bool isPalindrome(const char* input) {
    const char* start = input;
    const char* end = input;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        if (*start != *end) {
            return false;
        }

        start++;
        end--;
    }

    return true;
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

bool isPalindromeExcluding(const char* input, int skip1, int skip2) {

    int length = getLength(input);
    char* arraySkip = new char[length - 1];
    int index = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (i == skip1 || i == skip2) {
            continue;
        }

        arraySkip[index++] = input[i];

    }

    arraySkip[index] = '\0';

    if (!isPalindrome(arraySkip)) {
        delete[] arraySkip;
        return false;
    }

    delete[] arraySkip;
    return true;
}

bool checkStr(const char* input) {

    int length = getLength(input);


    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (isPalindromeExcluding(input, i, j)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Test 1
    const char* str1 = "racecar";
    bool res1 = checkStr(str1);
    std::cout << "--- Test 1 ---" << std::endl;
    std::cout << "Input: " << str1 << std::endl;
    std::cout << "Result: " << (res1 ? "true" : "false") << " (Expected: true)" << std::endl;
    

    // Test 2
    const char* str2 = "abxcba";
    bool res2 = checkStr(str2);
    std::cout << "--- Test 2 ---" << std::endl;
    std::cout << "Input: " << str2 << std::endl;
    std::cout << "Result: " << (res2 ? "true" : "false") << " (Expected: true)" << std::endl;
    

    // Test 3
    const char* str3 = "abcdef";
    bool res3 = checkStr(str3);
    std::cout << "--- Test 3 ---" << std::endl;
    std::cout << "Input: " << str3 << std::endl;
    std::cout << "Result: " << (res3 ? "true" : "false") << " (Expected: false)" << std::endl;

    // Test 4
    const char* str4 = "abcba";
    bool res4 = checkStr(str4);
    std::cout << "--- Test 4 ---" << std::endl;
    std::cout << "Input: " << str4 << std::endl;
    std::cout << "Result: " << (res4 ? "true" : "false") << " (Expected: true)" << std::endl;

    // Test 5
    const char* str5 = "a";
    bool res5 = checkStr(str5);
    std::cout << "--- Test 5 ---" << std::endl;
    std::cout << "Input: " << str5 << std::endl;
    std::cout << "Result: " << (res5 ? "true" : "false") << " (Expected: false)" << std::endl;

    return 0;
}
