#include <iostream>
using namespace std;
int analyzeArray(const char* str);
const int SIZE = 10;

int main()
{
    const char* t1 = "abc123456780";
    cout << "Input: \"" << t1 << "\" -> Output: " << analyzeArray(t1)
        << " (Expected: 9)" << endl << endl;

    const char* t2 = "Hello 1234567";
    cout << "Input: \"" << t2 << "\" -> Output: " << analyzeArray(t2)
        << " (Expected: 9)" << endl << endl;

    const char* t3 = "abc976543210";
    cout << "Input: \"" << t3 << "\" -> Output: " << analyzeArray(t3)
        << " (Expected: 8)" << endl << endl;

    const char* t4 = "0123456789 extra text";
    cout << "Input: \"" << t4 << "\" -> Output: " << analyzeArray(t4)
        << " (Expected: -1)" << endl << endl;

    const char* t5 = "No digits here!";
    cout << "Input: \"" << t5 << "\" -> Output: " << analyzeArray(t5)
        << " (Expected: 9)" << endl << endl;
}

int analyzeArray(const char* str) 
{
    if (str == nullptr)
    {
        return -1;
    }
    bool arr[SIZE] = {false};
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int cifra = str[i] - '0';
            arr[cifra] = true;
        }
    }
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (!arr[i])
        {
            return i;
        }
    }
    return -1;
}
