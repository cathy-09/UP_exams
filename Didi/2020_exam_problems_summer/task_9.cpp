#include <iostream>

char numToChar(int ascii) {
    return ascii + '0';
}

char* Encode(char* input) {

    char* pinput = input;

    if (input == nullptr || *input == '\0') {
        return nullptr;
    }

    int counter = 0;
    int separatprCounter = 0;

    while (*pinput != '\0') {
        int ascii = *pinput;

        if (ascii < 10) {
            counter++;
        }
        else if (ascii < 100) {
            counter += 2;
        }
        else {
            counter += 3;
        }

        pinput++;

        if (*pinput == '\0') {
            break;
        }

        separatprCounter++;
    }
    
    int length = counter + separatprCounter;

    char* result = new char[length + 1];
    int index = 0;

    while (*input != '\0')
    {
        int ascii = *input;

        if (ascii < 10) {
            result[index++] = numToChar(ascii);
        }
        else if (ascii < 100) {
            result[index++] = numToChar(ascii / 10);
            result[index++] = numToChar(ascii % 10);
        }
        else {
            result[index++] = numToChar(ascii / 100);
            result[index++] = numToChar(ascii / 10 % 10);
            result[index++] = numToChar(ascii % 10);
        }

        input++;

        if (*input == '\0') {
            break;
        }

        result[index++] = '_';
    }

    result[index] = '\0';

    return result;
}

int main() {
    // Test 1: Standard case without spaces
    char test1[] = "abc";
    std::cout << "--- Test 1: Standard case ---" << std::endl;
    std::cout << "Input: \"" << test1 << "\"" <<https://github.com/cathy-09/UP_exams/tree/main/Didi/2020_exam_problems std::endl;
    std::cout << "Expected output: 97_98_99" << std::endl;
    char* result1 = Encode(test1);
    std::cout << "Actual output:   " << (result1 ? result1 : "NULL") << std::endl;
    delete[] result1; // Assuming dynamic allocation with 'new char[]'
    std::cout << std::endl;

    // Test 2: Case with spaces
    char test2[] = " abc ";
    std::cout << "--- Test 2: Case with spaces ---" << std::endl;
    std::cout << "Input: \"" << test2 << "\"" << std::endl;
    std::cout << "Expected output: 32_97_98_99_32" << std::endl;
    char* result2 = Encode(test2);
    std::cout << "Actual output:   " << (result2 ? result2 : "NULL") << std::endl;
    delete[] result2;
    std::cout << std::endl;

    // Test 3: Single character
    char test3[] = "A";
    std::cout << "--- Test 3: Single character ---" << std::endl;
    std::cout << "Input: \"" << test3 << "\"" << std::endl;
    std::cout << "Expected output: 65" << std::endl;
    char* result3 = Encode(test3);
    std::cout << "Actual output:   " << (result3 ? result3 : "NULL") << std::endl;
    delete[] result3;
    std::cout << std::endl;

    return 0;
}
