#include <iostream>
using namespace std;
char* revandreplace(char* str);
int myCount(char array[]);

int main()
{
    char s1[] = "I left you alone";
    char* revRes = revandreplace(s1);
    cout << "\"I left you alone\" -> \"" << revRes << "\" (Expected: \"!nola uo* tf!l I\")" << endl;
    delete[] revRes;
    cout << endl;
}

char* revandreplace(char* str)
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int count = myCount(str);
    char* result = new char[count + 1];
    int j = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        char charche = str[i];
        if (charche == 'e')
        {
            charche = '!';
        }
        else if (charche == 'y')
        {
            charche = '*';
        }
        result[j] = charche;
        j++;
    }
    result[count] = '\0';

    return result;
}

int myCount(char array[])
{
    int count = 0;
    while (*array != '\0')
    {
        count++;
        array++;
    }
    return count;
}
