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
    char* strResult = new char[SIZE];
    int index = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        int charche = str[i]; 
        int digits[SIZE_DIGIT];
        int count = 0;
        if (charche == 0)
        {
            digits[count++] = 0;
        }
        while (charche > 0)
        {
            digits[count++] = charche % 10;
            charche /= 10;
        }
        for (int j = count - 1; j >= 0; j--)
        {
            strResult[index++] = digits[j] + '0';
        }
        if (str[i + 1] != '\0')
        {
            strResult[index++] = '_';
        }
    }
    strResult[index] = '\0';
    return strResult;
}
