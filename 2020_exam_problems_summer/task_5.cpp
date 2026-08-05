#include <iostream>

bool isUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isLetter(char c) {
    return isLowercase(c) || isUppercase(c);
}

int* cntWords(char str[]) {

    int lowerCtr = 0;
    int upperCtr = 0;

    bool isLower = true;
    bool isUpper = true;

    while (*str != '\0') {

        while ((*str == '\t' || *str == '\n' || *str == ' ') && *str != '\0') {
            str++;
        }

        if (*str == '\0') {
            break;
        }

        while (*str != '\t' && *str != '\n' && *str != ' ' && *str != '\0') {

            if (!isLetter(*str)) {
                str++;
                isLower = false;
                isUpper = false;
                continue;
            }

            if (isLowercase(*str)) {
                isUpper = false;
            }
            else if (isUppercase(*str)) {
                isLower = false;
            }

            str++;
        }

        if (isLower) {
            lowerCtr++;
        }
        else if (isUpper) {
            upperCtr++;
        }

        isUpper = true;
        isLower = true;
    }

    int* result = new int[2];
    result[0] = lowerCtr;
    result[1] = upperCtr;

    return result;
}

int main() {
    std::cout << "Running tests for cntWords...\n\n";

    // Test 1: The example from the description
    char str1[] = " This IS an exAMple STRING F&OR this eXErcise. ";
    int* res1 = cntWords(str1);
    if (res1[0] == 2 && res1[1] == 2) {
        std::cout << "Test 1 [PASS] - Example text\n";
    }
    else {
        std::cout << "Test 1 [FAIL] - Expected: {2, 2}, Actual: {" << res1[0] << ", " << res1[1] << "}\n";
    }

    // Test 2: Empty string
    char str2[] = "";
    int* res2 = cntWords(str2);
    if (res2[0] == 0 && res2[1] == 0) {
        std::cout << "Test 2 [PASS] - Empty string\n";
    }
    else {
        std::cout << "Test 2 [FAIL] - Expected: {0, 0}, Actual: {" << res2[0] << ", " << res2[1] << "}\n";
    }

    // Test 3: Only lowercase words
    char str3[] = "these are all lowercase words";
    int* res3 = cntWords(str3);
    if (res3[0] == 5 && res3[1] == 0) {
        std::cout << "Test 3 [PASS] - Only lowercase words\n";
    }
    else {
        std::cout << "Test 3 [FAIL] - Expected: {5, 0}, Actual: {" << res3[0] << ", " << res3[1] << "}\n";
    }

    // Test 4: Only uppercase words
    char str4[] = "THESE ARE ALL UPPERCASE WORDS";
    int* res4 = cntWords(str4);
    if (res4[0] == 0 && res4[1] == 5) {
        std::cout << "Test 4 [PASS] - Only uppercase words\n";
    }
    else {
        std::cout << "Test 4 [FAIL] - Expected: {0, 5}, Actual: {" << res4[0] << ", " << res4[1] << "}\n";
    }

    // Test 5: Mixed case words (should not be counted)
    char str5[] = "This String Has Mixed Case Words";
    int* res5 = cntWords(str5);
    if (res5[0] == 0 && res5[1] == 0) {
        std::cout << "Test 5 [PASS] - Mixed case words\n";
    }
    else {
        std::cout << "Test 5 [FAIL] - Expected: {0, 0}, Actual: {" << res5[0] << ", " << res5[1] << "}\n";
    }

    // Test 6: Words with numbers and symbols
    char str6[] = "word1 123 TEST! #HELLO text_";
    int* res6 = cntWords(str6);
    if (res6[0] == 0 && res6[1] == 0) {
        std::cout << "Test 6 [PASS] - Words with numbers/symbols\n";
    }
    else {
        std::cout << "Test 6 [FAIL] - Expected: {0, 0}, Actual: {" << res6[0] << ", " << res6[1] << "}\n";
    }

    std::cout << "\nTests finished.\n";

    return 0;
}
