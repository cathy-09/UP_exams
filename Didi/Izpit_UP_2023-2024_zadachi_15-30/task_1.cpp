#include <iostream>
    
int getArrLen(const char* arr) {
    if (arr == nullptr) {
        return 0;
    }

    int len = 0;

    while (*arr != '\0') {
        len++;
        arr++;
    }

    return len;
}

long findSeq(const char* arr, char S) {
    long maxLen = 0;
    long currentLen = 0;

    int arrLen = getArrLen(arr);

    for (size_t i = 0; i < arrLen; i++)
    {
        

        if (arr[i] == S) {
            currentLen++;
        }
        else {
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
            currentLen = 0;
        }
    }

    if (currentLen > maxLen) {
        maxLen = currentLen;
    }

    return maxLen;
}

int main() {
   
    std::cout << "TEST 1 (\"absssaasssbbba\", 's'): "
        << findSeq("absssaasssbbba", 's') << " (Expected: 3)\n";

    std::cout << "TEST 2 (\"aaabbbbaaa\", 'a'): "
        << findSeq("aaabbbbaaa", 'a') << " (Expected: 3)\n";

    std::cout << "TEST 3 (\"aaabbbbaaa\", 'b'): "
        << findSeq("aaabbbbaaa", 'b') << " (Expected: 4)\n";

    std::cout << "TEST 4 (\"hello world\", 'z'): "
        << findSeq("hello world", 'z') << " (Expected: 0)\n";

    std::cout << "TEST 5 (\"aaaaa\", 'a'): "
        << findSeq("aaaaa", 'a') << " (Expected: 5)\n";

    std::cout << "TEST 6 (\"\", 'a'): "
        << findSeq("", 'a') << " (Expected: 0)\n";

    std::cout << "TEST 7 (\"a\", 'a'): "
        << findSeq("a", 'a') << " (Expected: 1)\n";

    std::cout << "TEST 8 (\"b\", 'a'): "
        << findSeq("b", 'a') << " (Expected: 0)\n";
    
    return 0;
}
