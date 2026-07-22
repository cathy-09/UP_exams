#include <iostream>
using namespace std;
bool AnalyzeArr(int arr[], int length);

int main()
{
	int fixedArr1[] = { 0, 5, 2, 8 }; // arr[0]=0, arr[2]=2 -> 2 фиксирани
	int fixedArr2[] = { 1, 2, 3, 4 };
	cout << "{0, 5, 2, 8} -> " << (AnalyzeArr(fixedArr1, 4) ? "true" : "false") << " (Expected: true)" << endl;
	cout << "{1, 2, 3, 4} -> " << (AnalyzeArr(fixedArr2, 4) ? "true" : "false") << " (Expected: false)" << endl;
}

bool AnalyzeArr(int arr[], int length)
{
	if (arr == nullptr || length <= 0)
	{
		return false;
	}
	int count = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == i)
		{
			count++;
			if (count >= 2)
			{
				return true;
			}
		}
	}
	return false;
}
