//ABE GADNICHKA SI E

#include <iostream>

char* GetWord(char str[]) {
    if (str == nullptr) {
        return nullptr;
    }

    const char* pstr = str;

    int currentLen = 0;
    int maxLen = 0;
    int startIndex = 0;
    int maxIndex = 0;
    int index = 0;

    while (*pstr != '\0') {

        while (*pstr == '\n' || *pstr == ' ' || *pstr == '\t') {
            pstr++;
            index++;
        }

        if (*pstr == '\0') break;

        currentLen = 0;
        startIndex = index;

        while (*pstr != '\n' && *pstr != ' ' && *pstr != '\t' && *pstr != '\0') {
            pstr++;
            currentLen++;
            index++;
        }

        if (currentLen > maxLen) {
            maxLen = currentLen;
            maxIndex = startIndex;
        }
    }

    if (currentLen > maxLen) {
        maxLen = currentLen;
        maxIndex = startIndex;
    }

    char* result = new char[maxLen + 1];
    int resIndex = 0;

    for (size_t i = maxIndex; i < maxIndex + maxLen; i++)
    {
        result[resIndex++] = str[i];
    }

    result[resIndex] = '\0';

    return result;
}

int main() {

    std::cout << GetWord((char*)"    jsjs    ks   oirookd      o   ");
}
