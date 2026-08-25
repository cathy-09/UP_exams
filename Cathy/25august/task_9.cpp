#include <iostream>
int largestSeq(int arr[], int N);

int main()
{
    int arr1[] = { 2, 4, 3, 11, 12, 168, 144, 5, 9, 62, 98, 1 };
	std::cout << "Max even sequence sum: " << largestSeq(arr1, 12) << " (Expected: 324)" << std::endl << std::endl;
}

int largestSeq(int arr[], int N)
{
	if (arr == nullptr)
	{
		return -1;
	}
	int maxSum = 0;
	int currSum = 0;;
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0)
		{
			currSum = currSum + arr[i];
			if (currSum > maxSum)
			{
				maxSum = currSum;
			}
		}
		else
		{
			currSum = 0;
		}
	}
	return maxSum;
}
