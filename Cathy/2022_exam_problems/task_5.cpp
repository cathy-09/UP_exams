#include <iostream>
using namespace std;
int checkNum(long N, unsigned int m, unsigned int l);
bool isDivisibleBy4(long n);
const int SIZE = 16;

int main()
{
	cout << "N = 1234, m = 2, l = 4 -> " << checkNum(1234, 2, 4) << " (Expected: 1)" << endl;

	// N = 1234, разменяме 1 и 2 -> става 2134 (2134 не се дели на 4) -> Очакваме 0
	cout << "N = 1234, m = 1, l = 2 -> " << checkNum(1234, 1, 2) << " (Expected: 0)" << endl;

	// Невалидни позиции m или l извън броя цифри -> Очакваме -1
	cout << "N = 1234, m = 1, l = 5 (invalid index) -> " << checkNum(1234, 1, 5) << " (Expected: -1)" << endl;

	// N >= 10^9 -> Очакваме -1
	cout << "N = 1000000000 -> " << checkNum(1000000000, 1, 2) << " (Expected: -1)" << endl << endl;
}

int checkNum(long N, unsigned int m, unsigned int l)
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

	if (m < 1 || m > count || l < 1 || l > count)
	{
		return -1;
	}

	int idxM = count - m;
	int idxL = count - l;

	int tempDigit = arrray[idxM];
	arrray[idxM] = arrray[idxL];
	arrray[idxL] = tempDigit;

	long newNum = 0;
	for (int j = count - 1; j >= 0; j--)
	{
		newNum = newNum * 10 + arrray[j];
	}
	if (isDivisibleBy4(newNum))
	{
		return 1;
	}
	return 0;
}

bool isDivisibleBy4(long n)
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
	while (sum >= 4)
	{
		sum = sum - 4;
	}
	return sum == 0;
}
