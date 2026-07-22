#include <iostream>
using namespace std;
void ConvertNum(long& num);
const int SIZE = 256;

int main()
{
	long n1 = 12345;
	ConvertNum(n1);
	cout << "12345 -> " << n1 << " (Expected: 54321)" << endl << endl;
}

void ConvertNum(long& num)
{
	long number = num;
	if (number < 0)
	{
		number = -number;
	}
	int array[SIZE];
	int iCount = 0;
	while (number > 0)
	{
		array[iCount] = number % 10;
		iCount++;
		number = number / 10;
	}
	long reversedNum = 0;
	for (int i = 0; i < iCount; i++)
	{
		reversedNum = reversedNum * 10 + array[i];
	}
	if (num < 0)
	{
		num = -reversedNum;
	}
	else
	{
		num = reversedNum;
	}
}
