#include <iostream>


bool doExist(const char* symbols, const char* word) {

    const char* symbolsEnd = symbols;
    const char* wordEnd = word;
    const char* wordStart = word;
    int counter = 0;
    int wordLen = 0;

    while (*symbolsEnd != '\0') {
        symbolsEnd++;
    }
    symbolsEnd--;

    while (*wordEnd != '\0') {
        wordEnd++;
        wordLen++;
    }
    wordEnd--;

    while (*wordStart != '\0') {
        if (*symbolsEnd == *wordStart) {
            wordStart++;
            counter++;
        }
        else {
            wordStart = word;
            counter = 0;
        }

        if (*symbolsEnd == *wordEnd && counter == wordLen) {
            return true;
        }

        if (*symbolsEnd == *symbols) {
            break;
        }

        symbolsEnd--;
    }

    return false;
}

int main() {

    const char* symbols = "abcdef";
    const char* symbols2 = "abcdefe";

    std::cout << "Test 1 (\"edc\"): " << doExist(symbols, "edc") << " (true)\n";
    std::cout << "Test 2 (\"abe\"): " << doExist(symbols, "abe") << " (false)\n";
    std::cout << "Test 3 (\"fed\"): " << doExist(symbols, "fed") << " (true)\n";
    std::cout << "Test 4 (\"f\"): " << doExist(symbols, "f") << " (true)\n";
    std::cout << "Test 5 (\"ed\"): " << doExist(symbols2, "ed") << " (true)\n";

    return 0;
}
