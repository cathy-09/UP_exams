#include <iostream>
using namespace std;
char* CheckStr(char str[]);
const int SIZE = 256;

int main()
{
    char d1[] = "aif8sltt8f";
    char* dupRes = CheckStr(d1);
    cout << "\"aif8sltt8f\" -> \"" << dupRes << "\" (Expected: \"f8t\")" << endl;
    delete[] dupRes;
    cout << endl;
}

char* CheckStr(char str[])
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int array[SIZE] = {0};
    int iCount = 0;
    while (str[iCount] != '\0')
    {
        char charche = str[iCount];
        array[charche]++;
        iCount++;
    }

    int duplicatedCount = 0;
    bool added[SIZE] = { false };
    for (size_t i = 0; i < iCount; i++)
    {
        char charche = str[i];
        if (array[charche] > 1 && !added[charche])
        {
            added[charche] = true;
            duplicatedCount++;
        }
    }
    char* result = new char[duplicatedCount + 1];
    int index = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        added[i] = false;
    }
    for (size_t i = 0; i < iCount; i++)
    {
        char charche = str[i];
        if (array[charche] > 1 && !added[charche])
        {
            added[charche] = true;
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
    return result;
}
