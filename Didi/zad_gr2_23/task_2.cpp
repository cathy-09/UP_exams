#include <iostream>

const int MAX_SIZE = 10;

int getLength(long N) {
    if (N == 0) {
        return 0;
    }

    int len = 0;

    while (N != 0) {
        len++;
        N /= 10;
    }

    return len;
}

void mySwap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

int checkNum(long N, unsigned int m, unsigned int l) {

    if (N < 0) {
        N = -N;
    }

    if (N >= 1000000000) {
        return -1;
    }

    int length = getLength(N);

    if (m == 0 || l == 0 || m > length || l > length) {
        return -1;
    }

    int digits[MAX_SIZE] = { 0 };

    for (size_t i = 0; i < length; i++)
    {
        digits[length - i - 1] = N - (N / 10) * 10;
        N /= 10;
    }
    
    mySwap(digits[m - 1], digits[l - 1]);

    int num = 0;
    if (length == 1) {
        num = digits[0];
    }
    else {
        num = digits[length - 2] * 10 + digits[length - 1];
    }

    return num == (num / 4) * 4;
}

int main()
{
    // Valid inputs - the number IS divisible by 4 after the swap (Expected return: 1)
    std::cout << checkNum(123408, 5, 6) << std::endl; // 1 (0 and 8 swap -> 123480; 80 is divisible by 4)
    std::cout << checkNum(132, 1, 2) << std::endl;    // 1 (1 and 3 swap -> 312; 12 is divisible by 4)
    std::cout << checkNum(1004, 1, 1) << std::endl;   // 1 (Swapping digit with itself; 04 is divisible by 4)
    std::cout << checkNum(961, 2, 3) << std::endl;    // 1 (6 and 1 swap -> 916; 16 is divisible by 4)
    std::cout << checkNum(4445, 1, 4) << std::endl;   // 1 (4 and 5 swap -> 5444; 44 is divisible by 4)

    // Valid inputs - the number is NOT divisible by 4 after the swap (Expected return: 0)
    std::cout << checkNum(78, 1, 2) << std::endl;     // 0 (7 and 8 swap -> 87; 87 is not divisible by 4)
    std::cout << checkNum(123456, 5, 6) << std::endl; // 0 (5 and 6 swap -> 123465; 65 is not divisible by 4)
    std::cout << checkNum(20, 1, 2) << std::endl;     // 0 (2 and 0 swap -> 02; 2 is not divisible by 4)

    // Invalid inputs (Expected return: -1)
    std::cout << checkNum(1000000000, 1, 2) << std::endl; // -1 (N is not strictly less than 10^9)
    std::cout << checkNum(1234, 1, 5) << std::endl;       // -1 (Position 5 does not exist in a 4-digit number)
    std::cout << checkNum(1234, 5, 1) << std::endl;       // -1 (Position 5 does not exist)
    std::cout << checkNum(123, 0, 2) << std::endl;        // -1 (Position 0 is invalid; 1-based indexing)
    std::cout << checkNum(5, 1, 2) << std::endl;          // -1 (Number has only 1 digit; position 2 is out of bounds)

    return 0;
}
