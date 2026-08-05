#include <iostream>

long convertNumber(char* num) {

    if (num == nullptr) {
        return 0;
    }

    long sum = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;

    while (*num != '\0') {
        int ascii = *num;

        if (ascii > max1) {
            max3 = max2;
            max2 = max1;
            max1 = ascii;
        }
        else if (ascii > max2) {
            max3 = max2;
            max2 = ascii;
        }
        else if (ascii > max3) {
            max3 = ascii;
        }

        num++;
    }

    sum = max1 + max2 + max3;

    return sum;
}

// Helper function to format and run the tests
void runTest(const char* testName, char* input, long expected) {
    long actual = convertNumber(input);

    std::cout << "Test: " << testName << "\n";
    if (input != nullptr) {
        std::cout << "Input: \"" << input << "\"\n";
    }
    else {
        std::cout << "Input: nullptr\n";
    }

    std::cout << "Expected output: " << expected << "\n";
    std::cout << "Actual output:   " << actual << "\n";
    std::cout << "Result: " << (expected == actual ? "[PASS]" : "[FAIL]") << "\n";
    std::cout << "------------------------\n";
}

int main() {
    // Test 1: Standard word with 3 different characters
    // 'c'=99, 'a'=97, 't'=116 -> 116 + 99 + 97 = 312
    char test1[] = "cat";
    runTest("Normal string", test1, 312);

    // Test 2: Longer string, including repeating largest characters
    // 'o'=111, 'l'=108, 'l'=108 -> 111 + 108 + 108 = 327
    char test2[] = "Hello!";
    runTest("Longer string with duplicates", test2, 327);

    // Test 3: String with less than 3 characters
    // 'H'=72, 'i'=105, the third remains 0 -> 105 + 72 + 0 = 177
    char test3[] = "Hi";
    runTest("Less than 3 characters", test3, 177);

    // Test 4: Identical characters
    // 'z'=122 -> 122 + 122 + 122 = 366
    char test4[] = "zzz";
    runTest("Identical characters", test4, 366);

    // Test 5: Empty string
    // The three variables remain 0
    char test5[] = "";
    runTest("Empty string", test5, 0);

    // Test 6: Invalid pointer (nullptr)
    // The nullptr check directly returns 0
    runTest("Null pointer", nullptr, 0);

    return 0;
}
