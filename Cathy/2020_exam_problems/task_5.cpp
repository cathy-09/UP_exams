#include <iostream>
using namespace std;
bool checkstr(char* str);

int main()
{
    char cs1[] = "aZaAaCfEa";
    char cs2[] = "bAzCBaFbK";
    char cs3[] = "bAzC$aFbK";
    cout << "\"aZaAaCfEa\" -> " << (checkstr(cs1) ? "true" : "false") << " (Expected: true)" << endl;
    cout << "\"bAzCBaFbK\" -> " << (checkstr(cs2) ? "true" : "false") << " (Expected: false)" << endl;
    cout << "\"bAzC$aFbK\" -> " << (checkstr(cs3) ? "true" : "false") << " (Expected: false)" << endl << endl;
}

bool checkstr(char* str)
{
    if (str == nullptr || str[0] == '\0')
    {
        return false;
    }
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char charche = str[i];
        if (!(charche >= 'a' && charche <= 'z') || !(charche >= 'A' && charche <= 'Z'))
        {
            return false;
        }
        if (i > 0)
        {
            char previos = str[i - 1];
            if (((previos >= 'a' && previos <= 'z') && !(charche >= 'A' && charche <= 'Z')) || ((previos >= 'A' && previos <= 'Z') && !(charche >= 'a' && charche <= 'z')))
            {
                return false;
            }
        }
    }
    return true;
}
