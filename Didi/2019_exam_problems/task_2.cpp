//MISLEH CHE SHTE E PO_ZLE :)

#include <iostream>

const int MAX_SIZE = 256;

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

int CheckStr(char str[]) {

    int length = getLength(str);
    int reps[MAX_SIZE] = { 0 };

    if (str == nullptr || length < 2) {
        return -1;
    }

    for (size_t i = 0; i < length; i++)
    {
        int ascii = str[i];
        reps[ascii]++;
    }

    int oddCtr = 0;

    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        if (reps[i] == 0) continue;

        if (length % 2 == 0) {
            if (reps[i] % 2 != 0) {
                return 0;
            }
        }
        else {
            if (reps[i] % 2 != 0) {
                oddCtr++;
            }
        }

        if (oddCtr > 1) {
            return 0;
        }
    }

    return 1;
    
}

int main()
{
    std::cout << "\"beblehl\" -> " << CheckStr((char*)"beblehl") << " (1, ex: belhleb)" << std::endl;
    std::cout << "\"asdfgjk\" -> " << CheckStr((char*)"asdfgjk") << " (0, no palindrome)" << std::endl;
    std::cout << "NULL -> " << CheckStr(NULL) << " (-1, invalid input)" << std::endl;
    std::cout << "\"a\" -> " << CheckStr((char*)"a") << " (-1, length < 2)" << std::endl;
    std::cout << "\"\" -> " << CheckStr((char*)"") << " (-1, empty string)" << std::endl;
    std::cout << "\"aabb\" -> " << CheckStr((char*)"aabb") << " (1, ex: abba)" << std::endl;
    std::cout << "\"AABBc\" -> " << CheckStr((char*)"AABBc") << " (1, ex: ABcBA)" << std::endl;
    std::cout << "\"123321\" -> " << CheckStr((char*)"123321") << " (1, ex: 123321)" << std::endl;
    std::cout << "\"a!a!b\" -> " << CheckStr((char*)"a!a!b") << " (1, ex: a!b!a)" << std::endl;
}
