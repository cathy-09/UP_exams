#include <iostream>
void ConvertArr(long arr[], long S, long E);

int main()
{
	long arrToConv[] = { 4, 5, 6, 7, 8, 9, 0, 1 };
	ConvertArr(arrToConv, 2, 5);
	std::cout << "Converted: ";
	for (int i = 0; i < 8; i++) std::cout << arrToConv[i] << " ";
	std::cout << "(Expected: 4 5 9 8 7 6 0 1)" << std::endl << std::endl;
}

void ConvertArr(long arr[], long S, long E)
{
	if (arr == nullptr || S < 0 || E < S)
	{
		return;
	}
	while (S < E)
	{
		long temp = arr[S];
		arr[S] = arr[E];
		arr[E] = temp;
		S++;
		E--;
	}
}
