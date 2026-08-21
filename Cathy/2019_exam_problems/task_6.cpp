//ERROR

#include <iostream>
using namespace std;
int NumCalc(long num, int k, int l);
const int SIZE = 32;

int main()
{
	cout << "NumCalc(582914, 2, 4) -> " << NumCalc(582914, 2, 4) << " (Expected: 1 + 2 = 3)" << endl;
	cout << "NULL / Invalid -> " << NumCalc(582914, -1, 4) << " (Expected: -1)" << endl << endl;
}

int NumCalc(long num, int k, int l)
{
	if (num < 0)
	{
		num = -num;
	}
	if (k <= 0 || l <= 0)
	{
		return -1;
	}
	int digits[SIZE];
	int count = 0;
	if (num == 0)
	{
		digits[0] = 0;
		count = 1;
	}
	else
	{
		long number = num;
		while (number > 0)
		{
			digits[count++] = number % 10;
			number = number / 10;
		}
	}
	if (k > count || l > count)
	{
		return -1;
	}
	int indexK = digits[k - 1];
	int indexL = digits[l - 1];
	int sum = indexK + indexL;
	return sum;
}
