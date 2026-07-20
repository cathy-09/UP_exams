#include <iostream>
using namespace std;
int analyzeArr(const char* array);
int convertStringToNumber(const char charche);
int arrayCount(const char* array);
const int ARR_SIZE = 10;

int main()
{
	cout << analyzeArr("abc123xyz") << endl;        // Очакван изход: 9 (липсва, най-голяма)
	cout << analyzeArr("9876543210") << endl;       // Очакван изход: -1 (всички цифри ги има)
	cout << analyzeArr("95438210") << endl;         // Очакван изход: 7 (липсват 6 и 7)
	cout << analyzeArr("My phone is 988-765") << endl; // Очакван изход: 4
	cout << analyzeArr("No digits here!") << endl;   // Очакван изход: 9
}

int analyzeArr(const char* array)
{
	int count = arrayCount(array);
	bool found[ARR_SIZE] = { false };
	for (size_t i = 0; i < count; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
			int rez = convertStringToNumber(array[i]);
			found[rez] = true;
		}
	}
	for (int i = ARR_SIZE - 1; i >= 0; i--)
	{
		if (found[i] == false)
		{
			return i;
		}
	}
	return -1;
}

int arrayCount(const char* array)
{
	int count = 0;
	while (*array != '\0')
	{
		count++;
		array++;
	}
	return count;
}

int convertStringToNumber(const char charche)
{
	return charche - '0';
}
