#include <iostream>
using namespace std;
long findSeq(const char* arr, char S);
int myLen(const char* arr);

int main()
{
    cout << findSeq("baaacccb", 'a') << endl;       // Очакван изход: 3
    cout << findSeq("abcdef", 'x') << endl;          // Очакван изход: 0
    cout << findSeq("xxyyyxxyyyyx", 'y') << endl;   // Очакван изход: 4
    cout << findSeq("ssss", 's') << endl;            // Очакван изход: 4
}

long findSeq(const char* arr, char S)
{
    int len = myLen(arr);
    int max = 0;
    int curr = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == S)
        {
            curr++;
            if (max < curr)
            {
                max = curr;
            }
        }
        else
        {
            curr = 0;
        }
    }
    return max;
}

int myLen(const char* arr)
{
    int len = 0;
    while (*arr != '\0')
    {
        len++;
        arr++;
    }
    return len;
}
