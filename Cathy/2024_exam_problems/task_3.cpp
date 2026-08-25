#include <iostream>
using namespace std;
long processNum(long num);
const int SIZE = 32;

int main()
{
    // Намаляващи подредици: "54" (дължина 2), "983" (дължина 3), "21" (дължина 2). Най-дълга е 983.
    cout << "5498321 -> " << processNum(5498321) << " (983)" << endl;
    // Цялото число намалява
    cout << "97531 -> " << processNum(97531) << " (97531)" << endl;
    // Числото само расте -> всяка единична цифра е намаляваща подредица с дължина 1. Взимаме първата най-дълга (или последната, тук първата е 1).
    cout << "12345 -> " << processNum(12345) << " (1)" << endl;
    cout << endl;
}

long processNum(long num)
{
    if (num < 0)
    {
        num = -num;
    }
    int temp[SIZE];
    int tempCount = 0;
    while (num > 0)
    {
        temp[tempCount++] = num % 10;
        num = num / 10;
    }
    long max = 0;
    int maxLen = 0;
    long currNum = temp[0];
    int currLen = 1;
    long multiplyer = 10;
    for (size_t i = 1; i < tempCount; i++)
    {
        if (temp[i] > temp[i - 1])
        {
            currLen++; 
            currNum = currNum + (temp[i] * multiplyer);
            multiplyer = multiplyer * 10;
        }
        else
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                max = currNum;
            }
            currNum = temp[i];
            currLen = 1;
            multiplyer = 10;
        }
    }
    if (currLen > maxLen)
    {
        max = currNum;
    }

    return max;
}
