#include <iostream>
using namespace std;
void convertMax(int* arr, int N);
const int MAX_VALUE = -1234567890;

int main()
{
	int convArr[] = { 11, 5, 2, 27, 4, 8, 2 };
	convertMax(convArr, 7);
	cout << "Converted array: { ";
	for (int i = 0; i < 7; i++) cout << convArr[i] << (i < 6 ? ", " : " ");
	cout << "} (Expected: {29, 35, 31, 27, 29, 32, 38})" << endl << endl;
}

void convertMax(int* arr, int N)
{
	if (arr == nullptr || N <= 0)
	{
		return;
	}
    int max = MAX_VALUE;
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] == max)
		{
			continue;
		}
		else
		{
			arr[i] = arr[i] + max;
		}
	}
	int left = 0;
	int right = N - 1;
	while (left < right)
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
