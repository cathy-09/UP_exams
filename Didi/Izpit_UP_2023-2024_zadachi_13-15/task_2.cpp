#include <iostream>

int findIndex(const int arr[], size_t L) {

	int result = 0;
	int biggerThani = 0;

	for (size_t i = 1; i <= L; i++)
	{
		for (size_t j = 0; j < L; j++)
		{
			if (arr[j] >= i) {
				biggerThani++;
			}
		}

		if (biggerThani >= i) {
			result = i;
			biggerThani = 0;
		}
		else {
			break;
		}
	}

	return result;
}

int main()
{
	int arr2_1[] = { 10, 8, 5, 0, 3 };
	std::cout << findIndex(arr2_1, 5) << std::endl;//3

	int arr2_2[] = { 0, 1, 0, 2 };
	std::cout << findIndex(arr2_2, 4) << std::endl;//1

	int arr2_3[] = { 5, 5, 5, 5, 5 };
	std::cout << findIndex(arr2_3, 5) << std::endl;//5

	int arr2_4[] = { 0, 0, 0 };
	std::cout << findIndex(arr2_4, 3) << std::endl;//0
}
