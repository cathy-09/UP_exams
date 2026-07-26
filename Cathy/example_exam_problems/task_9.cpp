#include <iostream>
using namespace std;
int DigitPos(long num, int k);
const int SIZE = 32;

int main()
{
    cout << "DigitPos(12345, 3): " << DigitPos(12345, 3) << " (Expected: 3)" << endl;
    cout << "DigitPos(12345, 10): " << DigitPos(12345, 10) << " (Expected: -1)" << endl << endl;
}

int DigitPos(long num, int k)
{
    if (num < 0)
    {
        num = -num;
    }
    if (k <= 0)
    {
        return -1;
    }
    int array[SIZE];
    int count = 0;
    while (num > 0)
    {
        array[count] = num % 10;
        num = num / 10;
        count++;
    }
    if (k > count)
    {
        return -1;
    }
    return array[count - k];
}
