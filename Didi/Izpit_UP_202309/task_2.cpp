//NQMASHE PAK KAK DJEMBAKA DA NE SE NAMESI...

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
            if (counter > 0) {
                symbolsEnd += counter; //We move the pointer back to the right (by as many steps as we were wrong)
                counter = 0;
            }
            wordStart = word;
        }

        if (counter == wordLen) {
            return true;
        }

        if (symbolsEnd == symbols) {
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
    std::cout << "Test 6 (\"aab\" in \"baaa\"): " << doExist("baaa", "aab") << " (true)\n";
    return 0;
}
