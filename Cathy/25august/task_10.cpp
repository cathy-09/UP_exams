#include <iostream>
using namespace std;
int* numOfWords(char str[]);
const int SIZE = 2;

int main()
{
	char s1[] = " This is an example string ";
	int* wordsRes = numOfWords(s1);
	if (wordsRes)
	{
		cout << "Word lengths {even, odd}: {" << wordsRes[0] << ", " << wordsRes[1] << "} (Expected: {4, 1})" << endl;
		delete[] wordsRes;
	}
	cout << endl;
}

int* numOfWords(char array[])
{
	if (array == nullptr)
	{
		return nullptr;
	}
	int chetni = 0;
	int nechetni = 0;
	int curr = 0;
	for (size_t i = 0; array[i] != '\0'; i++)
	{
		char charche = array[i];
		if (charche != ' ' && charche != '\t')
		{
			curr++;
		}
		else if (curr > 0)
		{
			if (curr % 2 == 0)
			{
				chetni++;
			}
			else
			{
				nechetni++;
			}
			curr = 0;
		}
	}
	if (curr > 0)
	{
		if (curr % 2 == 0)
		{
			chetni++;
		}
		else
		{
			nechetni++;
		}
		curr = 0;
	}
	int* arr = new int[SIZE];
	arr[0] = chetni;
	arr[1] = nechetni;
	return arr;
}
