#include <iostream>

char* changeWord(char* str, char k) {

    if (str == nullptr || *str == '\0') 
    {
        return nullptr;
    }
    char* pointerStr = str;
    while (*pointerStr != '\0') 
    {
        while ((*pointerStr == '\t' || *pointerStr == '\n' || *pointerStr == ' ') && *pointerStr != '\0') 
        {
            pointerStr++;
        }
        if (*pointerStr == '\0') 
        {
            break;
        }
        bool isFirst = true;
        bool isFound = false;
        while ((*pointerStr != '\t' && *pointerStr != '\n' && *pointerStr != ' ') && *pointerStr != '\0')
        {
            if (*pointerStr == k && isFirst)
            {
                isFound = true;
                isFirst = false;
            }
            else 
            {
                isFirst = false;
            }

            if (isFound) 
            {
                *pointerStr = '*';
            }

            pointerStr++;
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
    std::cout << "Expected: This is a ** string" << std::endl;
    std::cout << "Output:   " << changeWord(str1, k1) << std::endl << std::endl;

    // Test 2: Character is inside the word, but not at the beginning
    char str2[] = "start at the end";
    char k2 = 't';

    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: start at * end" << std::endl;
    std::cout << "Output:   " << changeWord(str2, k2) << std::endl << std::endl;

    // Test 3: Multiple words starting with the target letter
    char str3[] = "tiny turtles talk to tall trees";
    char k3 = 't';

    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: **** ***** *******" << std::endl;std::cout << "Output:   " << changeWord(str3, k3) << std::endl << std::endl;
}
