#include <iostream>

const int SIZE = 10;

int getLen(long N) {
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

int AnalyzeNum(long N) {

    if (N < 0) {
        N = -N;
    }

    long Ncopy = N;
    int smallerCtr = 0;
    int biggerCtr = 0;
    
    int length = getLen(N);
    int uniqueDigits[SIZE] = { 0 };

    for (size_t i = 0; i < length; i++)
    {
        uniqueDigits[Ncopy % 10]++;
        Ncopy /= 10;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        if (uniqueDigits[i] == 0) {
            continue;
        }

        int current = i;

        for (size_t j = 0; j < SIZE; j++)
        {
            if (uniqueDigits[j] == 0 || j == current) {
                continue;
            }

            if (j > current) {
                biggerCtr++;
            }
            else if (j < current) {
                smallerCtr++;
            }
        }

        if (smallerCtr == biggerCtr) {

            if (smallerCtr == 0) return -1;

            return current;
        }
        
        smallerCtr = 0;
        biggerCtr = 0;
    }

    return -1;
}

int main() {
    std::cout << "Test 1 (314): " << AnalyzeNum(314) << " | Expected: 3\n";
    std::cout << "Test 2 (442): " << AnalyzeNum(442) << " | Expected: -1\n";
    std::cout << "Test 3 (5462141): " << AnalyzeNum(5462141) << " | Expected: 4\n";

    std::cout << "Test 4 (7777): " << AnalyzeNum(7777) << " | Expected: -1\n";
    std::cout << "Test 5 (12): " << AnalyzeNum(12) << " | Expected: -1\n";
    std::cout << "Test 6 (12321): " << AnalyzeNum(12321) << " | Expected: 2\n";
    std::cout << "Test 7 (1234): " << AnalyzeNum(1234) << " | Expected: -1\n";
    std::cout << "Test 8 (987654321): " << AnalyzeNum(987654321) << " | Expected: 5\n";
    std::cout << "Test 9 (102): " << AnalyzeNum(102) << " | Expected: 1\n";
    std::cout << "Test 10 (80808): " << AnalyzeNum(80808) << " | Expected: -1\n";

    return 0;
}
