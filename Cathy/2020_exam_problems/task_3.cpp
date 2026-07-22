#include <iostream>
using namespace std;
bool CheckDate(char date[]);
int myCount(char array[]);
bool leap(int year);

int main()
{
    char d1[] = "2020 g.";
    char d2[] = "2021 g.";
    cout << "\"2020 g.\" -> " << (CheckDate(d1) ? "true" : "false") << " (Expected: true)" << endl;
    cout << "\"2021 g.\" -> " << (CheckDate(d2) ? "true" : "false") << " (Expected: false)" << endl << endl;
}

bool CheckDate(char date[])
{
    if (date == nullptr)
    {
        return false;
    }
    int count = myCount(date);
    if (count != 7)
    {
        return false;
    }
    int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
    if (leap(year) && date[4] == ' ' && date[5] == 'g' && date[6] == '.')
    {
        return true;
    }
    return false;
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

bool leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}
