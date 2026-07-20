#include <iostream>
using namespace std;
bool checkNum(long num);
const int SIZE = 32;

int main()
{
    cout << "(12934 -> true): " << (checkNum(12934) ? "true" : "false") << endl;
    cout << "(98716 -> true): " << (checkNum(98716) ? "true" : "false") << endl;
    cout << "(15382 -> false): " << (checkNum(15382) ? "true" : "false") << endl;
    cout << "(42 -> true): " << (checkNum(42) ? "true" : "false") << endl;
    cout << endl;
}

bool checkNum(long num)
{
    if (num < 0)
    {
        num = -num;
    }
    int numbers[SIZE];
    int count = 0;
    if (num == 0)
    {
        numbers[count++] = 0;
    }
    while (num > 0)
    {
        numbers[count++] = num % 10;
        num = num / 10;
    }
    if (count <= 2) 
    {
        return true;
    }
    for (size_t i = 0; i < count; i++)
    {
        bool namalqvashta = true;
        bool rastqshta = true;
        int numbersTemp[SIZE];
        int countTemp = 0;
        for (size_t j = 0; j < count; j++)
        {
            if (i != j)
            {
                numbersTemp[countTemp++] = numbers[j];
            }
        }
        for (size_t k = 0; k < countTemp - 1; k++)
        {
            if (numbersTemp[k] < numbersTemp[k + 1])
            {
                namalqvashta = false;
            }
            if (numbersTemp[k] > numbersTemp[k + 1])
            {
                rastqshta = false;
            }
        }
        if (namalqvashta || rastqshta)
        {
            return true;
        }
    }
    return false;
}
