#include <iostream>

int* numOfWords(char input[]) {
    int evenCtr = 0;
    int oddCtr = 0;
    int letterCtr = 0;

    while (*input != '\0') {
        while ((*input == '\n' || *input == '\t' || *input == ' ') && *input != '\0') {
            input++;
            continue;
        }

        while (*input != '\n' && *input != '\t' && *input != ' ' && *input != '\0') {
            input++;
            letterCtr++;
        }

        if (letterCtr % 2 == 0 && letterCtr != 0) {
            evenCtr++;
        }
        else if (letterCtr % 2 != 0) {
            oddCtr++;
        }
        letterCtr = 0;
    }

    int* result = new int[2] { evenCtr, oddCtr };
    return result;
}

int main() {
    // Test 1: Example from prompt
    char t1[] = " This is an example string ";
    int* r1 = numOfWords(t1);
    std::cout << "Test 1 Input: \"" << t1 << "\"\n";
    std::cout << "Output:   {" << r1[0] << ", " << r1[1] << "}\n";
    std::cout << "Expected: {4, 1}\n\n";

    // Test 2: Multiple consecutive spaces
    char t2[] = "  Hello   world  ";
    int* r2 = numOfWords(t2);
    std::cout << "Test 2 Input: \"" << t2 << "\"\n";
    std::cout << "Output:   {" << r2[0] << ", " << r2[1] << "}\n";
    std::cout << "Expected: {0, 2}\n\n";

    // Test 3: Empty string
    char t3[] = "";
    int* r3 = numOfWords(t3);
    std::cout << "Test 3 Input: \"" << t3 << "\"\n";
    std::cout << "Output:   {" << r3[0] << ", " << r3[1] << "}\n";
    std::cout << "Expected: {0, 0}\n\n";

    // Test 4: Only spaces
    char t4[] = "    ";
    int* r4 = numOfWords(t4);
    std::cout << "Test 4 Input: \"" << t4 << "\"\n";
    std::cout << "Output:   {" << r4[0] << ", " << r4[1] << "}\n";
    std::cout << "Expected: {0, 0}\n\n";

    // Test 5: Single word without spaces
    char t5[] = "C++";
    int* r5 = numOfWords(t5);
    std::cout << "Test 5 Input: \"" << t5 << "\"\n";
    std::cout << "Output:   {" << r5[0] << ", " << r5[1] << "}\n";
    std::cout << "Expected: {0, 1}\n\n";

    // Test 6: Mixed lengths (1, 2, 3, 4 characters)
    char t6[] = "a bb ccc dddd";
    int* r6 = numOfWords(t6);
    std::cout << "Test 6 Input: \"" << t6 << "\"\n";
    std::cout << "Output:   {" << r6[0] << ", " << r6[1] << "}\n";
    std::cout << "Expected: {2, 2}\n";

    return 0;
}
