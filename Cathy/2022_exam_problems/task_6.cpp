#include <iostream>
using namespace std;
bool doExist(char* symbols, char* word);
int myCount(char array[]);

int main()
{
    char syms[] = "hello world";
    char w1[] = "dlrow";
    cout << "\"dlrow\" in reversed \"hello world\" -> " << (doExist(syms, w1) ? "true" : "false") << " (Expected: true)" << endl << endl;
}

bool doExist(char* symbols, char* word)
{
    if (symbols == nullptr || word == nullptr)
    {
        return false;
    }
    int countSymbols = myCount(symbols);
    int countWord = myCount(word);
    if (countWord == 0)
    {
        return true;
    }
    if (countWord > countSymbols)
    {
        return false;
    }
    for (int i = countSymbols - 1; i >= countWord - 1; i--)
    {
        bool ok = true;
        for (size_t j = 0; j < countWord; j++)
        {
            if (symbols[i - j] != word[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ok = true;
        }
    }
    false;
}

int myCount(char array[])
{
    int count = 0;
    while (*array != '\0')
    {
        count++;
        array++;
    }
    return count;
}
