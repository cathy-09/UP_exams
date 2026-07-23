//ZNAM CHE E TVURDE SLOJNO, MRAZQ Q 

#include <iostream>

int getLen(long num) {

    if (num == 0) {
        return 0;
    }

    int len = 0;
    while (num != 0) {
        len++;
        num /= 10;
    }

    return len;
}

long processNum(long number) {

    if (number < 0) {
        number = -number;
    }

    int length = getLen(number);

    if (length < 5) {
        return -1;
    }

    int maxLen = 0;
    int currentLen = 1;

    int* digits = new int[length];
    long numberCopy = number;

    for (size_t i = 0; i < length; i++)
    {
        digits[length - i - 1] = numberCopy % 10;
        numberCopy /= 10;
    }

    int* resultDigits = new int[length];
    int* tempDigits = new int[length];
    int index = 0;

    for (size_t i = 0; i < length - 1; i++)
    {
        bool isDescending = true;

        if (digits[i] > digits[i + 1]) {
            tempDigits[index++] = digits[i];
            currentLen++;
        }
        else {
            tempDigits[index++] = digits[i];
            isDescending = false;

            if (currentLen > maxLen) {

                for (size_t j = 0; j < length; j++)
                {
                    resultDigits[j] = 0;
                }

                for (size_t j = 0; j < index; j++) {
                    resultDigits[j] = tempDigits[j];
                }

                maxLen = currentLen;
            }

            for (size_t j = 0; j < length; j++) {
                tempDigits[j] = 0;
            }
            currentLen = 1;
            index = 0;
        }
    }

    tempDigits[index++] = digits[length - 1];
    if (currentLen > maxLen) {
        maxLen = currentLen;
        for (size_t j = 0; j < index; j++) {
            resultDigits[j] = tempDigits[j];
        }
    }

    long result = 0;
    int multiplier = 1;

    for (size_t i = 0; i < maxLen - 1; i++)
    {
        multiplier *= 10;
    }

    for (size_t i = 0; i < length; i++)
    {
        result += resultDigits[i] * multiplier;
        multiplier /= 10;
    }
    
    delete[] digits;
    delete[] resultDigits;
    delete[] tempDigits; 

    return result;
}


int main()
{
    std::cout << "5498321 -> " << processNum(5498321) << " (98321)" << std::endl;
    std::cout << "97531 -> " << processNum(97531) << " (97531)" << std::endl;
    std::cout << "12345 -> " << processNum(12345) << " (1)" << std::endl;
    std::cout << "1987612345 -> " << processNum(1987612345) << " (98761)" << std::endl;
    std::cout << "1234598761 -> " << processNum(1234598761) << " (98761)" << std::endl;
    std::cout << "1988765123 -> " << processNum(1988765123) << " (87651)" << std::endl;
    std::cout << "1864201234 -> " << processNum(1864201234) << " (86420)" << std::endl;

}

