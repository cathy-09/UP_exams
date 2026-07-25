//DJEMBAKA NQMASHE PAK KAK DA NE SE OBADI

#include <iostream>

int getLength(char* symbols) {

    if (symbols == nullptr) {
        return 0;
    }

    int len = 0;
    while (*symbols != '\0') {
        len++;
        symbols++;
    }

    return len;
}


bool doExist(char* symbols, char* word) {

    int symbolsLength = getLength(symbols);
    int wordLength = getLength(word);

    if (wordLength > symbolsLength) {
        return false;
    }

    int counter = 0;

    for (size_t i = 0; i < symbolsLength; i++)
    {
        if (symbols[symbolsLength - i - 1] == word[counter]) {
            counter++;
            if (counter == wordLength) {
                return true;
            }
        }
        else if (counter > 0) {
            i -= counter; // We move i back so as not to miss an overlap
            counter = 0;
        }
    }

    if (counter == wordLength) {
        return true;
    }

    return false;
}

void runTest(int testNum, char* symbols, char* word, bool expected) {
    bool result = doExist(symbols, word);
    std::cout << "Test " << testNum << ":\n";
    std::cout << "  symbols  : \"" << (symbols ? symbols : "NULL") << "\"\n";
    std::cout << "  word     : \"" << (word ? word : "NULL") << "\"\n";
    std::cout << "  Expected : " << (expected ? "1 (true)" : "0 (false)") << "\n";
    std::cout << "  Result   : " << (result ? "1 (true)" : "0 (false)") << "\n";
    std::cout << "  Status   : " << (result == expected ? "PASSED" : "FAILED") << "\n";
    std::cout << "----------------------------------------\n";
}

int main() {
    
    // Test 1: Standard middle substring match in reversed string ("edcba")
    char s1[] = "abcde";
    char w1[] = "dc";
    runTest(1, s1, w1, true);

    // Test 2: Exact full match ("olleh")
    char s2[] = "hello";
    char w2[] = "olleh";
    runTest(2, s2, w2, true);

    // Test 3: Original word should NOT match in reversed string ("olleh" vs "hello")
    char s3[] = "hello";
    char w3[] = "hello";
    runTest(3, s3, w3, false);

    // Test 4: Match with spaces ("terces pot")
    char s4[] = "top secret";
    char w4[] = "terces";
    runTest(4, s4, w4, true);

    // Test 5: Match at the very end of reversed string ("fedcba")
    char s5[] = "abcdef";
    char w5[] = "ba";
    runTest(5, s5, w5, true);

    // Test 6: Word length greater than symbols length
    char s6[] = "abc";
    char w6[] = "dcba";
    runTest(6, s6, w6, false);

    // Test 7: Palindrome check ("racecar")
    char s7[] = "racecar";
    char w7[] = "race";
    runTest(7, s7, w7, true);

    // Test 8: Overlap check ("baaa")
    char s8[] = "baaa";
    char w8[] = "aab";
    runTest(8, s8, w8, true);

    return 0;
}
