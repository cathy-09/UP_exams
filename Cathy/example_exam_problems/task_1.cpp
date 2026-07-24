#include <iostream>
using namespace std;
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2);
void BubbleSort(int* arr1, int size1);

int main()
{
  int a1[] = { 1, 3, 5, 7 };
  int a2[] = { 2, 4, 6, 8, 10 };
  int* merged = mergeSortedArrays(a1, 4, a2, 5);
  cout << "Merged: ";
  for (int i = 0; i < 9; i++) cout << merged[i] << " ";
  cout << "(Expected: 1 2 3 4 5 6 7 8 10)" << endl;
  delete[] merged;
  cout << endl;
}

int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2)
{
	int len = size1 + size2;
	int* result = new int[len];
	for (size_t i = 0; i < size1; i++)
	{
		result[i] = arr1[i];
	}
	for (size_t i = 0; i < size2; i++)
	{
		result[i + size1] = arr2[i];
	}
	BubbleSort(result, len);
	return result;
}

void BubbleSort(int* arr1, int size1)
{
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size1 - 1; j++)
		{
			if (arr1[j] > arr1[j + 1])
			{
				int temp = arr1[j]; 
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}
}
