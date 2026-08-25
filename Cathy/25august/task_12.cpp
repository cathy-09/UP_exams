#include <iostream>
using namespace std;
long newNum(long num);

int main()
{
    cout << "123456789 -> " << newNum(123456789) << " (Expected: 2468)" << endl;
    cout << "5783932 -> " << newNum(5783932) << " (Expected: 82)" << endl;
    cout << "400 -> " << newNum(400) << " (Expected: 400)" << endl; // Тест с нули
    cout << "135 -> " << newNum(135) << " (Expected: 0)" << endl;   // Без четни
}

long newNum(long num)
{
    if (num < 0)
    {
        num = -num;
    }
    long result = 0;
    long multiplier = 1;
    while (num > 0)
    {
        int digit = num % 10;
        if (digit % 2 == 0)
        {
            result = result + digit * multiplier;
            multiplier = multiplier * 10;
        }
        num = num / 10;
    }
    return result;
}
