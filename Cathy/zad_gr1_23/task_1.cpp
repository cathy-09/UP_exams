#include <iostream>
using namespace std;
int analyzeArr(char* str);
const int SIZE = 256;

int main()
{
    char s1[] = "hello";
    cout << "\"hello\" -> Unique: " << analyzeArr(s1) << " (Expected: 4)" << endl; // h, e, l, o

    char s2[] = "aaaaa";
    cout << "\"aaaaa\" -> Unique: " << analyzeArr(s2) << " (Expected: 1)" << endl;

    char s3[] = "a b c!";
    cout << "\"a b c!\" -> Unique: " << analyzeArr(s3) << " (Expected: 5)" << endl; // a, ' ', b, c, !

    cout << "nullptr -> " << analyzeArr(nullptr) << " (Expected: -1)" << endl;
    cout << endl;
}

int analyzeArr(char* str)
{
    if (str == nullptr)
    {
        return -1;
    }
    int count = 0;
    bool visited[SIZE] = { false };
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char sybol = str[i];
        if (!visited[sybol])
        {
            visited[sybol] = true;
            count++;
        }
    }
    return count;
}
