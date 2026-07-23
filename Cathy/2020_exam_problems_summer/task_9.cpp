#include <iostream>
using namespace std;
char* Encode(char* str);
const int SIZE = 256;
const int SIZE_DIGIT = 3;

int main()
{
    char encStr[] = "abc";
    char* encoded = Encode(encStr);
    cout << "\"abc\" encoded: \"" << encoded << "\" (Expected: \"97_98_99\")" << endl;
    delete[] encoded;
}

char* Encode(char* str)
{
    if (str == nullptr)
    {
        return nullptr;
    }
    char* result = new char[SIZE];
    int pos = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int code = str[i];
        int digits[SIZE_DIGIT];
        int count = 0;
        if (code == 0)
        {
            digits[count++] = 0;
        }
        while (code > 0)
        {
            digits[count++] = code % 10;
            code /= 10;
        }
        for (int j = count - 1; j >= 0; j--)
        {
            result[pos++] = digits[j] + '0';
        }
        if (str[i + 1] != '\0')
        {
            result[pos++] = '_';
        }
    }
    result[pos] = '\0';
    return result;
}
