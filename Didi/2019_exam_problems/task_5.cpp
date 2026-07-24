#include <iostream>

const int MAX_LENGTH = 256;

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

char* CheckStr(char str[]) {

    if (str == nullptr) {
        return nullptr;
    }

    int length = getLength(str);

    if (length == 1) {
        return nullptr;
    }

    int reps[MAX_LENGTH] = { 0 };

    for (size_t i = 0; i < length; i++)
    {
        int ascii = str[i];
        reps[ascii]++;
    }

    int uniqueCounter = 0;

    for (size_t i = 0; i < MAX_LENGTH; i++)
    {
        if (reps[i] > 1) {
            uniqueCounter++;
        }
    }

    char* result = new char[uniqueCounter + 1];
    int index = 0;
    

    //alternatively just add the repeated characters
   /* for (size_t i = 0; i < MAX_LENGTH; i++)
    {
        if (reps[i] > 1) {
            result[index++] = char(i);
        }
    }*/


    // Add the repeated characters IN THE ORDER they appear in str
    for (size_t i = 0; i < length; i++){
        int ascii = str[i];

        if (reps[ascii] > 1) {
            result[index++] = str[i];
            reps[ascii] = 0; //mark as added
        }
    }

    result[index] = '\0';

    return result;
}

int main()
{
    // Test Case 1: Standard example with digits and letters
    char test1[] = "aif8sltt8f";
    std::cout << "Input:    \"" << test1 << "\"\n";
    std::cout << "Expected: \"f8t\"\n";
    char* res1 = CheckStr(test1);
    std::cout << "Actual:   \"" << res1 << "\"\n\n";
    delete[] res1; // Free dynamic memory

    // Test Case 2: No repeated characters
    char test2[] = "asdfgjk";
    std::cout << "Input:    \"" << test2 << "\"\n";
    std::cout << "Expected: \"\"\n";
    char* res2 = CheckStr(test2);
    std::cout << "Actual:   \"" << res2 << "\"\n\n";
    delete[] res2;

    // Test Case 3: All characters are identical
    char test3[] = "aaaaa";
    std::cout << "Input:    \"" << test3 << "\"\n";
    std::cout << "Expected: \"a\"\n";
    char* res3 = CheckStr(test3);
    std::cout << "Actual:   \"" << res3 << "\"\n\n";
    delete[] res3;

    // Test Case 4: Multiple repeating letters in a word
    char test4[] = "programming";
    std::cout << "Input:    \"" << test4 << "\"\n";
    std::cout << "Expected: \"rgm\"\n";
    char* res4 = CheckStr(test4);
    std::cout << "Actual:   \"" << res4 << "\"\n\n";
    delete[] res4;

    // Test Case 5: Empty string boundary test
    char test5[] = "";
    std::cout << "Input:    \"" << test5 << "\"\n";
    std::cout << "Expected: \"\"\n";
    char* res5 = CheckStr(test5);
    std::cout << "Actual:   \"" << res5 << "\"\n\n";
    delete[] res5;

    return 0;
}
