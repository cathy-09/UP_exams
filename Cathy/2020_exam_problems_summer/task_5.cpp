#include <iostream>
using namespace std;
int* cntWords(char str[]);
const int SIZE = 2;

int main()
{
    char s2[] = " This IS an exAMple STRING F&OR this eXErcise. ";
    int* cntRes = cntWords(s2);
    if (cntRes)
    {
        cout << "{lowerOnly, upperOnly}: {" << cntRes[0] << ", " << cntRes[1] << "} (Expected: {2, 2})" << endl;
        delete[] cntRes;
    }
    cout << endl;
}

int* cntWords(char str[])
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int lowerOnlyCount = 0;
    int upperOnlyCount = 0;
    int currLen = 0;
    bool hasOnlyLower = true;
    bool hasOnlyUpper = true;
    for (size_t i = 0; str[i] != '\0'; i++)
    {

        char charche = str[i]; 
        if (!(charche == ' ' || charche == '\t'))
        {
            currLen++;
            if (!(charche >= 'a' && charche <= 'z'))
            {
                hasOnlyLower = false;
            }
            if (!(charche >= 'A' && charche <= 'Z'))
            {
                hasOnlyUpper = false;
            }
        }
        else
        {
            if (currLen > 0)
            {
                if (hasOnlyLower)
                {
                    lowerOnlyCount++;
                }
                if (hasOnlyUpper)
                {
                    upperOnlyCount++;
                }

                currLen = 0;
                hasOnlyLower = true;
                hasOnlyUpper = true;
            }
        }
    }

    if (currLen > 0)
    {
        if (hasOnlyLower)
        {
            lowerOnlyCount++;
        }
        if (hasOnlyUpper)
        {
            upperOnlyCount++;
        }
    }

    int* result = new int[SIZE];
    result[0] = lowerOnlyCount;
    result[1] = upperOnlyCount;

    return result;
}
