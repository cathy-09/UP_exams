#include <iostream>
using namespace std;

char* encodeWord(char* str, int N);
int myCount(char* str);

int main()
{
    char w1[] = "ABC";
    char* res1 = encodeWord(w1, 2);
    if (res1 != nullptr)
    {
        cout << "\"ABC\", N=2 -> " << res1 << " (Expected: CDE)" << endl;
        delete[] res1;
    }
    char w2[] = "Hello";
    char* res2 = encodeWord(w2, 5);
    if (res2 != nullptr)
    {
        cout << "\"Hello\", N=5 -> " << res2 << " (Expected: Mjqqt)" << endl;
        delete[] res2;
    }
    char* res3 = encodeWord(w1, 1);
    cout << "\"ABC\", N=1  -> " << (res3 == nullptr ? "nullptr" : res3) << " (Expected: nullptr)" << endl;
    char w4[] = "Test~";
    char* res4 = encodeWord(w4, 2);
    if (res4 != nullptr)
    {
        cout << "\"Test~\", N=2 -> " << res4 << endl;
        delete[] res4;
    }
}

char* encodeWord(char* str, int N)
{
    if (str == nullptr || N < 2 || N > 49)
    {
        return nullptr;
    }
    int count = myCount(str);
    for (size_t i = 0; i < count; i++)
    {
        if (str[i] < 32 || str[i] > 126)
        {
            return nullptr;
        }
    }
    char* result = new char[count + 1];
    for (size_t i = 0; i < count; i++)
    {
        int shiftedCode = str[i] + N;
        if (shiftedCode > 126)
        {
            shiftedCode = 32 + (shiftedCode - 127);
        }
        result[i] = (char)shiftedCode;
    }
    result[count] = '\0';
    return result;
}

int myCount(char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
