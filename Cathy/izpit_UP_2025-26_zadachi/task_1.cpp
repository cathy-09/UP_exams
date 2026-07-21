#include <iostream>
using namespace std;
char* GetWord(const char* str);

int main()
{
    char* w1 = GetWord("  C++   is awesome  ");
    cout << "\"  C++   is awesome  \" -> " << w1 << " (: awesome)" << endl;
    delete[] w1; 

    char* w2 = GetWord("\tHello\tworld");
    cout << "\"\ \tHello\ \tworld\" -> " << w2 << " (: Hello)" << endl;
    delete[] w2;
    cout << endl;
}

char* GetWord(const char* str)
{
    int maxCount = 0;
    const char* maxIndex = nullptr;
    int currCount = 0;
    const char* currIndex = nullptr;
    while (*str != '\0')
    {
        if (*str != '\t' && *str != ' ')
        {
            if (currCount == 0)
            {
                currIndex = str;
            }
            currCount++;
        }
        else
        {
            if (currCount > maxCount)
            {
                maxCount = currCount;
                maxIndex = currIndex;
            }
            currCount = 0;
        }
        str++;
    }

    if (currCount > maxCount)
    {
        maxCount = currCount;
        maxIndex = currIndex;
    }
    char* result = new char[maxCount + 1];
    for (size_t i = 0; i < maxCount; i++)
    {
        result[i] = maxIndex[i];
    }
    result[maxCount] = '\0';
    return result;
}
