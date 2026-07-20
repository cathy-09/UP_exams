#include <iostream>
using namespace std;
bool doExist(const char* sybols, const char* word);
int myLen(const char* array);
const int SIZE = 32;

int main()
{
    cout << (doExist("abcdefgh", "fed") ? "true" : "false") << endl;
    cout << (doExist("abcdefgh", "def") ? "true" : "false") << endl;
    cout << (doExist("racecar_test", "racecar") ? "true" : "false") << endl;
    cout << (doExist("abc", "cbaxt") ? "true" : "false") << endl;

    cout << endl;
}

bool doExist(const char* sybols, const char* word)
{
    int countSybols = myLen(sybols);
    int countWord = myLen(word);

    if (countWord > countSybols)
    {
        return false;
    }

    char reversedWord[SIZE];
    int index = 0;
    for (int i = countWord - 1; i >= 0; i--)
    {
        reversedWord[index] = word[i];
        index++;
    }
    reversedWord[index] = '\0';
    for (size_t i = 0; i <= countSybols - countWord; i++)
    {
        bool match = true;
        for (size_t j = 0; j < countWord; j++)
        {
            if (sybols[i + j] != reversedWord[j])
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
