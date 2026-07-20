//Mnogo sulzi i malko pomosh ot gemini po-kusno

#include <iostream>

long long myAbs(long long num) {
    return num > 0 ? num : -num;
}

long getNumLen(long num) {
    if (num == 0) {
        return 1;
    }

    long len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

long getBiggerNum(long first, long second) {
    return first > second ? first : second;
}

long getSmalerNum(long first, long second) {
    return first < second ? first : second;
}

void numToString(long num, char* str) {
    if (str == nullptr) return;

    int i = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    while (num > 0) {
        long digit = num % 10;
        str[i++] = digit + '0';
        num /= 10;
    }

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* findDiff(const long arr[], size_t N) {
    if (N < 2) return nullptr;

    long long minDiff = -1;
    long resultLen = 0;
    long firstNum = arr[0];
    long secondNum = arr[1];

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            long long currentDiff = myAbs(arr[i] - arr[j]);

            if (minDiff == -1 || currentDiff < minDiff) {
                minDiff = currentDiff;

                firstNum = getBiggerNum(arr[i], arr[j]);
                secondNum = getSmalerNum(arr[i], arr[j]);

                resultLen = getNumLen(firstNum) + 1 + getNumLen(secondNum) + 1;
            }
        }
    }

    char* result = new char[resultLen];

    numToString(firstNum, result);
    result[getNumLen(firstNum)] = ',';
    numToString(secondNum, result + getNumLen(firstNum) + 1);

    return result;
}

int main() {
    const size_t N = 4;
    long arr[N] = { 120, 15, 125, 50 };

    char* res = findDiff(arr, N);
    if (res != nullptr) {
        std::cout << "Result: " << res << std::endl;
        delete[] res; 
    }

    return 0;
}
