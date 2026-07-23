//BUKV KOPIRAH OT PREDNIQ DEN HAHAHAH

#include <iostream>

const int DATE_LENGTH = 10;
const int FIRST_SEPARATOR_INDEX = 2;
const int SECOND_SEPARATOR_INDEX = 5;
const char SEPARATOR = '.';

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

int charToNumber(char c) {
    if (!isNumber(c)) {
        return 0;
    }

    return c - '0';
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysByMonthNum(int month, int year) {

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    default:
        return 0;
    }
}

bool validDate(const char* input) {
    int len = getLength(input);

    if (len != DATE_LENGTH) {
        return false;
    }

    if (input[FIRST_SEPARATOR_INDEX] != SEPARATOR
        || input[SECOND_SEPARATOR_INDEX] != SEPARATOR) {
        return false;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (i == FIRST_SEPARATOR_INDEX || i == SECOND_SEPARATOR_INDEX) {
            continue;
        }

        if (!isNumber(input[i])) {
            return false;
        }
    }

    int days = charToNumber(input[0]) * 10 + charToNumber(input[1]);
    int month = charToNumber(input[FIRST_SEPARATOR_INDEX + 1]) * 10 + charToNumber(input[FIRST_SEPARATOR_INDEX + 2]);
    int year = charToNumber(input[SECOND_SEPARATOR_INDEX + 1]) * 1000 + charToNumber(input[SECOND_SEPARATOR_INDEX + 2]) * 100
        + charToNumber(input[SECOND_SEPARATOR_INDEX + 3]) * 10 + charToNumber(input[SECOND_SEPARATOR_INDEX + 4]);

    if (days <= 0 || year < 0) {
        return false;
    }

    if (days > daysByMonthNum(month, year)) {
        return false;
    }

    return true;
}

int main()
{
    std::cout << validDate("01.01.2024") << std::endl; // true
    std::cout << validDate("29.02.2024") << std::endl; // true
    std::cout << validDate("29.02.2023") << std::endl; // false 
    std::cout << validDate("31.04.2024") << std::endl; // false
    std::cout << validDate("30.04.2024") << std::endl; // true
    std::cout << validDate("31.12.1999") << std::endl; // true
    std::cout << validDate("00.01.2024") << std::endl; // false
    std::cout << validDate("15.13.2024") << std::endl; // false
    std::cout << validDate("32.01.2024") << std::endl; // false
    std::cout << validDate("1-1-2024") << std::endl;   // false
    std::cout << validDate("15/08/2024") << std::endl; // false

}
