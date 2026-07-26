#include <iostream>
using namespace std;
void Revert(char str[]);

int main()
{
    char revStr[] = "Hello World 123!";
    Revert(revStr);
    cout << "Reverted: " << revStr << " (Expected: hELLO wORLD 123!)" << endl << endl;
}

void Revert(char str[])
{
    if (str == nullptr)
    {
        return;
    }
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
