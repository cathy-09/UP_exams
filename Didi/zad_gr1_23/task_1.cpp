#include <iostream>

const int MAX_SIZE = 256;

int analyzeArr(char* arr) {
    if (arr == nullptr) {
        return -1;
    }

    int repetitions[MAX_SIZE] = { 0 };
    int uniqueCtr = 0;

    while (*arr != '\0') {
        repetitions[*arr]++;

        if (repetitions[*arr] == 1) {
            uniqueCtr++;
        }

        arr++;
    }


    return uniqueCtr;
}

int main()
{
    std::cout << "nullptr -> " << analyzeArr(nullptr) << " (-1)" << std::endl;
    std::cout << "\"\" -> " << analyzeArr((char*)"") << " (0)" << std::endl;
    std::cout << "\"a\" -> " << analyzeArr((char*)"a") << " (1)" << std::endl;
    std::cout << "\"aaaaa\" -> " << analyzeArr((char*)"aaaaa") << " (1)" << std::endl;
    std::cout << "\"abcdef\" -> " << analyzeArr((char*)"abcdef") << " (6)" << std::endl;
    std::cout << "\"hello\" -> " << analyzeArr((char*)"hello") << " (4)" << std::endl;
    std::cout << "\"123321\" -> " << analyzeArr((char*)"123321") << " (3)" << std::endl;
    std::cout << "\"AaBb!!\" -> " << analyzeArr((char*)"AaBb!!") << " (5)" << std::endl;
    std::cout << "\"hello world\" -> " << analyzeArr((char*)"hello world") << " (8)" << std::endl;
}

