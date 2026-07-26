//Vtoriq put ne beshe tolkova zle :)

#include <iostream>

int AnalyzeArray(int arr[], int l) {

	if (l <= 0 || arr == nullptr) {
		return -1;
	}

	if (l == 1) {
		return 0;
	}


	if (l == 2) {
		return arr[0] == arr[1];
	}

	int sum = 0;

	for (size_t i = 0; i < l; i++)
	{
		sum += arr[i];
	}

	if (sum % 2 != 0) {
		return 0;
	}

	int leftSum = 0;
	
	for (size_t i = 0; i < l - 1; i++)
	{
		leftSum += arr[i];

		if (sum - leftSum == leftSum) {
			return 1;
		}
	}

	return 0;
}

int main()
{
	int a1[] = { 1, 3, 0, 0, 4 }; std::cout << "{1, 3, 0, 0, 4}, 5 -> " << AnalyzeArray(a1, 5) << " (1)" << std::endl;
	int a2[] = { 1, 6, 1, 0, 5, 199 }; std::cout << "{1, 6, 1, 0, 5, 199}, 6 -> " << AnalyzeArray(a2, 6) << " (0)" << std::endl;
	int a3[] = { 2, 2 }; std::cout << "{2, 2}, 2 -> " << AnalyzeArray(a3, 2) << " (1)" << std::endl;
	int a4[] = { 1, 2, 3, 4 }; std::cout << "{1, 2, 3, 4}, 4 -> " << AnalyzeArray(a4, 4) << " (0)" << std::endl;
	int a5[] = { 10, 2, 3, 5 }; std::cout << "{10, 2, 3, 5}, 4 -> " << AnalyzeArray(a5, 4) << " (1)" << std::endl;
	int a6[] = { -1, 1, 5, -5 }; std::cout << "{-1, 1, 5, -5}, 4 -> " << AnalyzeArray(a6, 4) << " (1)" << std::endl;
	int a7[] = { 5 }; std::cout << "{5}, 1 -> " << AnalyzeArray(a7, 1) << " (0)" << std::endl;
	std::cout << "nullptr, 0 -> " << AnalyzeArray(nullptr, 0) << " (-1)" << std::endl;
	int a8[] = { 1, 2, 3 }; std::cout << "{1, 2, 3}, -1 -> " << AnalyzeArray(a8, -1) << " (-1)" << std::endl;
}
