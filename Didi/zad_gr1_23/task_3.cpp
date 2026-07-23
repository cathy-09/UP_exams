#include <iostream>

int getLength(char* input) {
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

char* encodeWord(char* input, int N) {

    if (!(N >= 2 && N <= 49) || input == nullptr) {
        return nullptr;
    }

    int length = getLength(input);

    for (int i = 0; i < length; i++) {
        unsigned char c = input[i];

        if (!(c >= 32 && c <= 126)) {
            return nullptr;
            if (c + N > 126) {
                return nullptr;
            }
        }
    }
        char* result = new char[length + 1];

        for (size_t i = 0; i < length; i++)
        {
            int asciiCode = input[i];
            result[i] = (asciiCode + N);
        }

        result[length] = '\0';

        return result;
}

int main()
{
    std::cout << "\"Hello\", 3 -> " << encodeWord((char*)"Hello", 3) << " (Khoor)" << std::endl;
    std::cout << "\"ABC\", 2 -> " << encodeWord((char*)"ABC", 2) << " (CDE)" << std::endl;
    std::cout << "\"abc\", 5 -> " << encodeWord((char*)"abc", 5) << " (fgh)" << std::endl;
    std::cout << "\"123\", 4 -> " << encodeWord((char*)"123", 4) << " (567)" << std::endl;
    std::cout << "\"a b\", 2 -> " << encodeWord((char*)"a b", 2) << " (c\"d)" << std::endl;
    std::cout << "\"!\", 49 -> " << encodeWord((char*)"!", 49) << " (R)" << std::endl;
    std::cout << "\"x\", 6 -> " << encodeWord((char*)"x", 6) << " (~)" << std::endl;
    std::cout << "\"Test\", 10 -> " << encodeWord((char*)"Test", 10) << " (^o}~)" << std::endl;
    std::cout << "\"\", 5 -> " << encodeWord((char*)"", 5) << " ()" << std::endl;
}

