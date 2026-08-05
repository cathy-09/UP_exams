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

char* getWord(char* str, int k) {

    char* pstr = str;
    int wordCounter = 0;
    int wordLen = 0;
    int index = 0;
    int endIndex = 0;
    bool isFound = false;
    

    while (*pstr != '\0') {
        while ((*pstr == '\t' || *pstr == '\n' || *pstr == ' ') && *pstr != '\0') {
            pstr++;
            index++;
        }

        if (*pstr == '\0') {
            break;
        }

        wordLen = 0;
        endIndex = 0;

        while ((*pstr != '\t' && *pstr != '\n' && *pstr != ' ') && *pstr != '\0') {
            pstr++;
            index++;
            wordLen++;
        }

        wordCounter++;

        if (wordCounter == k) {
            endIndex = index;
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        return (char*)"Wrong number!";
    }

    char* result = new char[wordLen + 1];
    int wordIndex = 0;
    
    for (size_t i = endIndex - wordLen; i < endIndex; i++)
    {
        if (isLower(str[i])) {
            result[wordIndex++] = toUpper(str[i]);
        }
        else if (isUpper(str[i])) {
            result[wordIndex++] = toLower(str[i]);
        }
        else { 
            result[wordIndex++] = str[i];
        }
    }

    result[wordIndex] = '\0';

    return result;
}

int main()
{
    // Test 1: From the example
    char str1[] = "this is a teSt string";
    int k1 = 4;
    char* res1 = getWord(str1, k1);

    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: TEsT" << std::endl;
    std::cout << "Output:   " << (res1 ? res1 : "nullptr") << std::endl << std::endl;

    // Test 2: Single character word
    char str2[] = "a";
    int k2 = 1;
    char* res2 = getWord(str2, k2);

    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: A" << std::endl;
    std::cout << "Output:   " << (res2 ? res2 : "nullptr") << std::endl << std::endl;

    // Test 3: Index greater than the number of words
    char str3[] = "s";
    int k3 = 5;
    char* res3 = getWord(str3, k3);

    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: Wrong number!" << std::endl;
    std::cout << "Output:   " << (res3 ? res3 : "nullptr") << std::endl << std::endl;

    // Test 4: Multiple spaces and tabs between words
    char str4[] = " \t  \t hello \t  WORLD  \t \t test  ";
    int k4 = 2;
    char* res4 = getWord(str4, k4);

    std::cout << "Test 4:" << std::endl;
    std::cout << "Expected: world" << std::endl;
    std::cout << "Output:   " << (res4 ? res4 : "nullptr") << std::endl;

    // Memory deallocation is omitted here as it depends on your function's implementation 
    // (e.g., whether "Wrong number!" is dynamically allocated or a string literal).

    return 0;
}
