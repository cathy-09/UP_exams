#include <iostream>

const int FIRST_SEPARATOR_INDEX = 2;
const int SECOND_SEPARATOR_INDEX = 5;
const int LENGTH = 8;
const char SEPARATOR = ':';

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

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int charToInt(char c) {
    return c - '0';
}

int CheckTimeStr(char input[]) {

    if (input == nullptr) {
        return -1;
    }

    int length = getLength(input);

    if (length != LENGTH) {
        return -1;
    }

    if (input[FIRST_SEPARATOR_INDEX] != SEPARATOR || input[SECOND_SEPARATOR_INDEX] != SEPARATOR) {
        return -1;
    }

    for (size_t i = 0; i < LENGTH; i++)
    {
        if (i == FIRST_SEPARATOR_INDEX || i == SECOND_SEPARATOR_INDEX) {
            continue;
        }

        if (!isNumber(input[i])) {
            return -1;
        }
    }

    int hours = charToInt(input[0]) * 10 + charToInt(input[1]);

    if (!(hours >= 0 && hours <= 24)) {
        return -1;
    }

    int minutes = charToInt(input[FIRST_SEPARATOR_INDEX + 1]) * 10 + charToInt(input[FIRST_SEPARATOR_INDEX + 2]);

    if (!(minutes >= 0 && minutes < 60)) {
        return -1;
    }

    int seconds = charToInt(input[SECOND_SEPARATOR_INDEX + 1]) * 10 + charToInt(input[SECOND_SEPARATOR_INDEX + 2]);

    if (!(seconds >= 0 && seconds < 60)) {
        return -1;
    }

    return 1;
}

int main()
{
    std::cout << "12:30:45 -> " << CheckTimeStr((char*)"12:30:45") << " (1, valid time)" << std::endl;
    std::cout << "00:00:00 -> " << CheckTimeStr((char*)"00:00:00") << " (1, lower bound)" << std::endl;
    std::cout << "23:59:59 -> " << CheckTimeStr((char*)"23:59:59") << " (1, valid time)" << std::endl;
    std::cout << "24:00:00 -> " << CheckTimeStr((char*)"24:00:00") << " (1, upper bound for 24h)" << std::endl;
    std::cout << "NULL -> " << CheckTimeStr(NULL) << " (-1, null pointer)" << std::endl;
    std::cout << " -> " << CheckTimeStr((char*)"") << " (-1, empty string)" << std::endl;
    std::cout << "12:30 -> " << CheckTimeStr((char*)"12:30") << " (-1, incomplete format)" << std::endl;
    std::cout << "12:30:45:00 -> " << CheckTimeStr((char*)"12:30:45:00") << " (-1, string too long)" << std::endl;
    std::cout << "25:00:00 -> " << CheckTimeStr((char*)"25:00:00") << " (-1, hours out of range 0-24)" << std::endl;
    std::cout << "12:60:00 -> " << CheckTimeStr((char*)"12:60:00") << " (-1, minutes out of range 0-59)" << std::endl;
    std::cout << "12:30:60 -> " << CheckTimeStr((char*)"12:30:60") << " (-1, seconds out of range 0-59)" << std::endl;
    std::cout << "12-30-45 -> " << CheckTimeStr((char*)"12-30-45") << " (-1, invalid delimiter)" << std::endl;
    std::cout << "ab:cd:ef -> " << CheckTimeStr((char*)"ab:cd:ef") << " (-1, contains letters)" << std::endl;
    std::cout << "1:2:3 -> " << CheckTimeStr((char*)"1:2:3") << " (-1, missing leading zeros)" << std::endl;
    std::cout << "12:30:45  -> " << CheckTimeStr((char*)"12:30:45 ") << " (-1, trailing whitespace)" << std::endl;
}
