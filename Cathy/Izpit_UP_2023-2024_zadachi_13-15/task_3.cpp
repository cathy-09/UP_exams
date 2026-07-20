#include <iostream>
using namespace std;
char* findDiff(const long arr[], size_t N);
char convertStringToNumber(const int num);
const int MNOGO_GOLQMO_CHISLO = 2147483647;
const int SIZE_ARRAY = 32;

int main()
{
	long arr3_1[] = { 10, 22, 50, 42, 18 };
	char* res3_1 = findDiff(arr3_1, 5);
	cout << res3_1 << endl;                           // Очакван изход: 22,18
	delete[] res3_1;

	long arr3_2[] = { 5, 15, 25, 35 };
	char* res3_2 = findDiff(arr3_2, 4);
	cout << res3_2 << endl;                           // Очакван изход: 15,5
	delete[] res3_2;

	long arr3_3[] = { 100, 101 };
	char* res3_3 = findDiff(arr3_3, 2);
	cout << res3_3 << endl;                           // Очакван изход: 101,100
	delete[] res3_3;

	long arr_poqsnenie[] = { 30, 25, 100, 85, 80 };
	char* res_poqsnenie = findDiff(arr_poqsnenie, 5);
	cout << res_poqsnenie << endl;                     // Очакван изход: 30,25
	delete[] res_poqsnenie;
}

char* findDiff(const long arr[], size_t N)
{
	int min = MNOGO_GOLQMO_CHISLO;
	int first = 0;
	int second = 0;
	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			int curr = 0;
			if (arr[i] > arr[j])
			{
				curr = arr[i] - arr[j];
			}
			else
			{
				curr = arr[j] - arr[i];
			}
			if (curr < min)
			{
				min = curr;

				if (arr[i] >= arr[j])
				{
					first = arr[i];
					second = arr[j];
				}
				else
				{
					first = arr[j];
					second = arr[i];
				}
			}
		}
	}

	char* newArray = new char[SIZE_ARRAY];

	int index = 0;

	char firstNum[SIZE_ARRAY];
	int firstCount = 0;

	char secondNum[SIZE_ARRAY];
	int secondCount = 0;

	if (first == 0)
	{
		firstNum[firstCount++] = convertStringToNumber(0);
	}
	while (first > 0)
	{
		firstNum[firstCount++] = convertStringToNumber(first % 10);
		first /= 10;
	}
	for (int i = firstCount - 1; i >= 0; i--)
	{
		newArray[index++] = firstNum[i];
	}

	newArray[index++] = ',';

	if (second == 0)
	{
		secondNum[secondCount++] = convertStringToNumber(0);
	}
	while (second > 0)
	{
		secondNum[secondCount++] = convertStringToNumber(second % 10);
		second /= 10;
	}
	for (int i = secondCount - 1; i >= 0; i--)
	{
		newArray[index++] = secondNum[i];
	}

	newArray[index] = '\0';

	return newArray;
}

char convertStringToNumber(const int num)
{
	return num + '0';
}
