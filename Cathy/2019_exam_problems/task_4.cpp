#include <iostream>
using namespace std;
int CheckTimeStr(char str[]);
int myCount(char array[]);
const int FORMAT = 8;

int main()
{
    char t1[] = "23:59:00";
    char t2[] = "25:00:00";
    cout << "\"23:59:00\" -> " << CheckTimeStr(t1) << " (Expected: 1)" << endl;
    cout << "\"25:00:00\" -> " << CheckTimeStr(t2) << " (Expected: -1)" << endl << endl;
}

int CheckTimeStr(char str[])
{
    if (str == nullptr)
    {
        return -1;
    }
    int count = myCount(str);
    if (count != FORMAT)
    {
        return -1;
    }
    if (str[2] != ':' || str[5] != ':')
    {
        return -1;
    }
    for (size_t i = 0; i < FORMAT; i++)
    {
        if (i == 2 || i == 5)
        {
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
        {
            return -1;
        }
    }
    int secundi = (str[6] - '0') * 10 + (str[7] - '0');
    int minuti = (str[3] - '0') * 10 + (str[4] - '0');
    int chasove = (str[0] - '0') * 10 + (str[1] - '0');
    if ((chasove < 0 || chasove > 24) || (minuti < 0 || minuti > 59) || (secundi < 0 || secundi > 59))
    {
        return -1;
    }
    if (chasove == 24 && (minuti > 0 || secundi > 0))
    {
        return -1;
    }
    return 1;
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
