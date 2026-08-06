//Gorda sum
#include <iostream>

bool doExist(char* symbols, char* word) {

    if (symbols == nullptr) {
        return false;
    }

    if (word == nullptr || *word == '\0') {
        return true;
    }

    int wordIndex = 0;

    char* pword = word;
    char* psymbols = symbols;

    while (*psymbols != '\0') {
        while (*psymbols == *pword) {
            psymbols++;
            pword++;
            wordIndex++;

            if (*pword == '\0') {
                return true;
            }
        }

        psymbols -= wordIndex;
        pword = word;
        wordIndex = 0;
        psymbols++;
    }

    return false;
}


int main() {
    std::cout << std::boolalpha; // Print booleans as true/false instead of 1/0

    // Test 1: Standard match in the middle
    char sym1[] = "the quick brown fox";
    char word1[] = "brown";
    std::cout << "Test 1: Standard match in the middle\n";
    std::cout << "Symbols: \"" << sym1 << "\", Word: \"" << word1 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym1, word1) << "\n\n";

    // Test 2: Match at the beginning
    char sym2[] = "hello world";
    char word2[] = "hello";
    std::cout << "Test 2: Match at the beginning\n";
    std::cout << "Symbols: \"" << sym2 << "\", Word: \"" << word2 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym2, word2) << "\n\n";

    // Test 3: Match at the end
    char sym3[] = "cplusplus programming";
    char word3[] = "programming";
    std::cout << "Test 3: Match at the end\n";
    std::cout << "Symbols: \"" << sym3 << "\", Word: \"" << word3 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym3, word3) << "\n\n";

    // Test 4: Completely missing word
    char sym4[] = "data structures";
    char word4[] = "algorithm";
    std::cout << "Test 4: Word completely missing\n";
    std::cout << "Symbols: \"" << sym4 << "\", Word: \"" << word4 << "\"\n";
    std::cout << "Expected: false\n";
    std::cout << "Actual:   " << doExist(sym4, word4) << "\n\n";

    // Test 5: Partial match (prefix matches, but fails at the end)
    char sym5[] = "abracadabra";
    char word5[] = "cadabrax";
    std::cout << "Test 5: Partial match (fails at the last character)\n";
    std::cout << "Symbols: \"" << sym5 << "\", Word: \"" << word5 << "\"\n";
    std::cout << "Expected: false\n";
    std::cout << "Actual:   " << doExist(sym5, word5) << "\n\n";

    // Test 6: Overlapping partial match before a full match
    char sym6[] = "aaaaab";
    char word6[] = "aaab";
    std::cout << "Test 6: Overlapping partial match before a full match\n";
    std::cout << "Symbols: \"" << sym6 << "\", Word: \"" << word6 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym6, word6) << "\n\n";

    // Test 7: Exact identical strings
    char sym7[] = "exact match";
    char word7[] = "exact match";
    std::cout << "Test 7: Exact identical strings\n";
    std::cout << "Symbols: \"" << sym7 << "\", Word: \"" << word7 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym7, word7) << "\n\n";

    // Test 8: Word is longer than the symbols string
    char sym8[] = "hi";
    char word8[] = "hello";
    std::cout << "Test 8: Word is longer than the symbols string\n";
    std::cout << "Symbols: \"" << sym8 << "\", Word: \"" << word8 << "\"\n";
    std::cout << "Expected: false\n";
    std::cout << "Actual:   " << doExist(sym8, word8) << "\n\n";

    // Test 9: Empty word (An empty string is mathematically a substring of any string)
    char sym9[] = "anything";
    char word9[] = "";
    std::cout << "Test 9: Empty word\n";
    std::cout << "Symbols: \"" << sym9 << "\", Word: \"" << word9 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym9, word9) << "\n\n";

    // Test 10: Empty symbols string but non-empty word
    char sym10[] = "";
    char word10[] = "missing";
    std::cout << "Test 10: Empty symbols string, non-empty word\n";
    std::cout << "Symbols: \"" << sym10 << "\", Word: \"" << word10 << "\"\n";
    std::cout << "Expected: false\n";
    std::cout << "Actual:   " << doExist(sym10, word10) << "\n\n";

    // Test 11: Both strings are empty
    char sym11[] = "";
    char word11[] = "";
    std::cout << "Test 11: Both strings are empty\n";
    std::cout << "Symbols: \"" << sym11 << "\", Word: \"" << word11 << "\"\n";
    std::cout << "Expected: true\n";
    std::cout << "Actual:   " << doExist(sym11, word11) << "\n\n";

    // Test 12: Case sensitivity check
    char sym12[] = "Case Sensitive";
    char word12[] = "case";
    std::cout << "Test 12: Case sensitivity check\n";
    std::cout << "Symbols: \"" << sym12 << "\", Word: \"" << word12 << "\"\n";
    std::cout << "Expected: false\n";
    std::cout << "Actual:   " << doExist(sym12, word12) << "\n\n";

    return 0;
}
