#include <iostream>
using namespace std;
int checkNum(long N);
bool isDivisibleBy3(long n);
const int SIZE = 16;

int main()
{
	cout << "N = 124 -> : " << checkNum(124) << " (Expected: 1)" << endl;

	// N = 111 -> Махаме произволна цифра -> остава 11 (сума 2 - не се дели).
	cout << "N = 111 -> : " << checkNum(111) << " (Expected: 0)" << endl;

	// N = -124 -> Отрицателно число, махаме '1' (позиция 1) -> остава -24 (дели се на 3).
	cout << "N = -124 -> : " << checkNum(-124) << " (Expected: 1)" << endl;

	// Некоректни данни (|N| >= 10^9)
	cout << "N = 1000000000 -> " << checkNum(1000000000) << " (Expected: -1)" << endl;
	cout << endl;
}

int checkNum(long N)
{
	long abs = N;
	if (abs < 0)
	{
		abs = -abs;
	}
	if (abs >= 1000000000)
	{
		return -1;
	}
	int arrray[SIZE];
	int count = 0;
	if (abs == 0)
	{
		arrray[0] = 0;
		count = 1;
	}
	else
	{
		long absN = abs;
		while (absN > 0)
		{
			int cifra = absN - (absN / 10) * 10;
			arrray[count++] = cifra;
			absN = absN / 10;
		}
	}
	for (size_t i = 0; i < count; i++)
	{
		int index = count - i - 1;
		long newNumber = 0;
		for (int j = count - 1; j >= 0; j--)
		{
			if (j == index)
			{
				continue;
			}
			newNumber = newNumber * 10 + arrray[j];
		}
		if (isDivisibleBy3(newNumber))
		{
			return i + 1;
		}
	}
	return 0;
}

bool isDivisibleBy3(long n)
{
	if (n < 0)
	{
		n = -n;
	}
	long sum = 0;
	while (n > 0)
	{
		int cifra = n - (n / 10) * 10;
		sum = sum + cifra;
		n = n / 10;
	}
	while (sum >= 3)
	{
		sum = sum - 3;
	}
	return sum == 0;
}
