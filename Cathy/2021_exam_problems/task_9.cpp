//ABSOLUTEN AD
#include <iostream>
using namespace std;
char* changeWord(char* str, char k);
int myCount(char array[]);

int main()
{
    char cwStr[] = "This is a test string";
    char* cwRes = changeWord(cwStr, 't');
    cout << "(k='t') \"This is a test string\" -> \"" << cwRes << "\"" << endl;
    cout << "(Expected: **** is a **** string)" << endl;
    delete[] cwRes;
}

char* changeWord(char* str, char k)
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int count = myCount(str);
    char* result = new char[count + 1];
    char kLower = ' ';
    if (k >= 'A' && k <= 'Z')
    {
        kLower = k - 'A' + 'a';
    }
    else
    {
        kLower = k;
    }
    int startWord = -1;
    for (size_t i = 0; ; i++)
    {
        char charche = str[i];
        if (!(charche == ' ' || charche == '\t' || charche == '\0'))
        {
            if (startWord == -1)
            {
                startWord = i;
                result[i] = charche;
                char firstCharche = charche;
                if (firstCharche >= 'A' && firstCharche <= 'Z')
                {
                    firstCharche = firstCharche - 'A' + 'a';
                }

                if (firstCharche == kLower)
                {
                    result[i] = '*';
                }
            }
            else
            {
                if (result[startWord] == '*')
                {
                    result[i] = '*';
                }
                else
                {
                    result[i] = charche;
                }
            }
        }
        else
        {
            startWord = -1;
            result[i] = charche;
        }
        if (charche == '\0')
        {
            break;
        }
    }
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
