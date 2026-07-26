#include <iostream>
using namespace std;
bool doExist(const char* sybols, const char* word);
int myLen(const char* array);
const int SIZE = 512;

int main()
{
    char syms[] = "This is a simple test";
    char w1[] = "simple";
    char w2[] = "complex";
    cout << "\"simple\" exists? " << (doExist(syms, w1) ? "true" : "false") << " (Expected: true)" << endl;
    cout << "\"complex\" exists? " << (doExist(syms, w2) ? "true" : "false") << " (Expected: false)" << endl;
}

bool doExist(const char* sybols, const char* word)
{
    int countSybols = myLen(sybols);
    int countWord = myLen(word);
    if (countWord > countSybols)
    {
        return false;
    }
    for (size_t i = 0; i <= countSybols - countWord; i++)
    {
        bool match = true;
        for (size_t j = 0; j < countWord; j++)
        {
            if (sybols[i + j] != word[j])
            {
                match = false;
                break;
            }
        }
        if (match == true)
        {
            return true;
        }
    }
    return false;
}

int myLen(const char* array)
{
    int count = 0;
    while (*array != '\0')
    {
        count++;
        array++;
    }
    return count;
}
