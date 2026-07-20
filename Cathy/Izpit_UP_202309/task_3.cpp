#include <iostream>
using namespace std;
const int BITS = 16;
unsigned short int reverseBitwise(unsigned short int num);

int main()
{
    cout << reverseBitwise(65535) << endl;
    cout << reverseBitwise(1) << endl;
    cout << reverseBitwise(43690) << endl;
    cout << reverseBitwise(0) << endl;
}

unsigned short int reverseBitwise(unsigned short int num)
{
    unsigned short int result = 0;
    for (size_t i = 0; i < BITS; i++)
    {
        int lastBit = 0;
        result = result * 2;
        lastBit = num % 2;
        result = result + lastBit;
        num = num / 2;
    }
    return result;
}
