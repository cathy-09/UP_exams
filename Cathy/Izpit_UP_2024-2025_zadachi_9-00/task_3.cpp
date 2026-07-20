#include <iostream>
using namespace std;
int convert(const char* str, int k);
int getDigitValue(char charche);

int main()
{
    cout << convert("101", 2) << " (5)" << endl;
    cout << convert("1A", 16) << " (26)" << endl;
    cout << convert("1a", 16) << " (26)" << endl;
    cout << convert("Z", 36) << " (35)" << endl;
}

int convert(const char* str, int k)
{
    int result = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        result = (result * k) + getDigitValue(str[i]);
    }
    return result;
}

int getDigitValue(char charche)
{
    if (charche >= '0' && charche <= '9')
    {
        return charche - '0';
    }
    if (charche >= 'a' && charche <= 'z')
    {
        return charche - 'a' + 10;
    }
    if (charche >= 'A' && charche <= 'Z')
    {
        return charche - 'A' + 10;
    }
}
