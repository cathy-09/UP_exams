#include <iostream>
using namespace std;
long newNum(long num);

int main()
{
    cout << "123456789 -> " << newNum(123456789) << " (Expected: 2468)" << endl;
    cout << "5783932 -> " << newNum(5783932) << " (Expected: 82)" << endl << endl;
}

long newNum(long num)
{
    if (num < 0)
    {
        num = -num;
    }
    if (num == 0)
    {
        return 0;
    }
    long temp = num;
    long reversedEvenDigits = 0;
    int evenCount = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 0)
        {
            reversedEvenDigits = reversedEvenDigits * 10 + digit;
            evenCount++;
        }
        temp = temp / 10;
    }
    if (evenCount == 0)
    {
        return 0;
    }
    long result = 0;
    while (reversedEvenDigits > 0)
    {
        result = result * 10 + (reversedEvenDigits % 10);
        reversedEvenDigits = reversedEvenDigits / 10;
    }
    return result;
}
