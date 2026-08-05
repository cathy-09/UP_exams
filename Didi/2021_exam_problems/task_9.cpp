#include <iostream>

char* changeWord(char* str, char k) {

    if (str == nullptr || *str == '\0') {
        return nullptr;
    }

    char* pstr = str;
    
    while (*pstr != '\0') {
        while ((*pstr == '\t' || *pstr == '\n' || *pstr == ' ') && *pstr != '\0') {
            pstr++;
        }

        if (*pstr == '\0') {
            break;
        }

        bool isFirst = true;
        bool isFound = false;
       
        while ((*pstr != '\t' && *pstr != '\n' && *pstr != ' ') && *pstr != '\0') {
        
            if (*pstr == k && isFirst) {
                isFound = true;
                isFirst = false;
            }
            else {
                isFirst = false;
            }

            if (isFound) {
                *pstr = '*';
            }

            pstr++;
        }

    }

    return str;
}

int main()
{
    // Test 1: From the example
    char str1[] = "This is a test string";
    char k1 = 't';

    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: This is a **** string" << std::endl;
    std::cout << "Output:   " << changeWord(str1, k1) << std::endl << std::endl;

    // Test 2: Character is inside the word, but not at the beginning
    char str2[] = "start at the end";
    char k2 = 't';

    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: start at *** end" << std::endl;
    std::cout << "Output:   " << changeWord(str2, k2) << std::endl << std::endl;

    // Test 3: Multiple words starting with the target letter
    char str3[] = "tiny turtles talk to tall trees";
    char k3 = 't';

    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: **** ******* **** ** **** *****" << std::endl;
    std::cout << "Output:   " << changeWord(str3, k3) << std::endl << std::endl;

    // Test 4: Handling tabs, multiple spaces, and single character words
    char str4[] = " \t apple \t banana \t apricot \t a ";
    char k4 = 'a';

    std::cout << "Test 4:" << std::endl;
    std::cout << "Expected:  \t ***** \t banana \t ******* \t * " << std::endl;
    std::cout << "Output:   " << changeWord(str4, k4) << std::endl << std::endl;

    // Test 5: No words starting with the given letter
    char str5[] = "Hello world";
    char k5 = 'z';

    std::cout << "Test 5:" << std::endl;
    std::cout << "Expected: Hello world" << std::endl;
    std::cout << "Output:   " << changeWord(str5, k5) << std::endl;

    return 0;
}
