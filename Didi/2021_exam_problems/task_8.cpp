#include <iostream>

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

int maxWord(char* str) {

    if (str == nullptr || *str == '\0') {
        return 0;
    }

    char* pstr = str;
    int wordCounter = 0;
    int maxLen = 0;
    int currentLen = 0;
    int lowerNum = 0;
    int maxLowerNum = 0;

    while (*pstr != '\0') {
        while ((*pstr == '\t' || *pstr == '\n' || *pstr == ' ') && *pstr != '\0') {
            pstr++;
        }

        if (*pstr == '\0') {
            break;
        }

       
        while ((*pstr != '\t' && *pstr != '\n' && *pstr != ' ') && *pstr != '\0') {
            if (isLower(*pstr)) {
                lowerNum++;
            }

            pstr++;
            currentLen++;
        }

        if (currentLen > maxLen) {
            maxLen = currentLen;
            maxLowerNum = lowerNum;
        }

        currentLen = 0;
        lowerNum = 0;

        wordCounter++;
    }

    return maxLen * maxLowerNum;
}

int main()
{
    // Test 1: From the example
    char str1[] = "This is a string";
    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: 36" << std::endl;
    std::cout << "Output:   " << maxWord(str1) << std::endl << std::endl;

    // Test 2: From the example
    char str2[] = "This is aNothEr string";
    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: 35" << std::endl;
    std::cout << "Output:   " << maxWord(str2) << std::endl << std::endl;

    // Test 3: String with numbers, punctuation, and multiple tabs/spaces
    char str3[] = " \t Testing \t long3st_word!! \t  ";
    // "Testing" -> length 7
    // "long3st_word!!" -> length 14, 10 lowercases (l,o,n,g,s,t,w,o,r,d) -> 14 * 10 = 140
    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: 140" << std::endl;
    std::cout << "Output:   " << maxWord(str3) << std::endl << std::endl;

    // Test 4: Only uppercase letters
    char str4[] = "HELLO WORLD";
    // Length 5, 0 lowercases -> 5 * 0 = 0
    std::cout << "Test 4:" << std::endl;
    std::cout << "Expected: 0" << std::endl;
    std::cout << "Output:   " << maxWord(str4) << std::endl << std::endl;

    // Test 5: Empty or whitespace only string
    char str5[] = " \t  \t  ";
    std::cout << "Test 5:" << std::endl;
    std::cout << "Expected: 0" << std::endl;
    std::cout << "Output:   " << maxWord(str5) << std::endl;

    return 0;
}
