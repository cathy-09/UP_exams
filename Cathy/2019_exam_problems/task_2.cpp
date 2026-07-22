//Да се напише функция на С++, със сигнатура int CheckStr(char[]), 
// която проверява, дали символите на входния масив, който трябва 
// да е с дължина поне 2 символа, може да се пренаредят така, че той да стане палиндром.
// Функцията да връща -1, при невалидни входни данни.

#include <iostream>
using namespace std;
int CheckStr(char array[]);
int myCount(char array[]);
const int SIZE = 128;

int main()
{
    char s1[] = "beblehl";
    char s2[] = "asdfgjk";
    cout << "\"beblehl\" -> " << CheckStr(s1) << " (Expected: 1)" << endl;
    cout << "\"asdfgjk\" -> " << CheckStr(s2) << " (Expected: 0)" << endl;
    cout << "NULL -> " << CheckStr(nullptr) << " (Expected: -1)" << endl << endl;
}

int CheckStr(char array[])
{
    if (array == nullptr)
    {
        return -1;
    }
    int count = myCount(array);
    if (count <= 2)
    {
        return -1;
    }
    int chestota[SIZE] = { 0 };
    for (size_t i = 0; array[i] != '\0'; i++)
    {
        char charche = array[i];
        chestota[charche]++;
    }
    int nechetenCount = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        if (chestota[i] % 2 != 0)
        {
            nechetenCount++;
        }
    }
    bool uslovie = nechetenCount <= 1;
    return uslovie;
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
