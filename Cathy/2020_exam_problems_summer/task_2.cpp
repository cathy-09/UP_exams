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

int* numOfWords(char str[])
{
	if (str == nullptr)
	{
		return nullptr;
	}
	int chetnoCount = 0;
	int nechetnoCount = 0;
	int currCount = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		char charche = str[i];
		if (charche != ' ' && charche != '\t')
		{
			currCount++;
		}
		else if (currCount > 0)
		{
			if (currCount % 2 == 0)
			{
				chetnoCount++;
			}
			else
			{
				nechetnoCount++;
			}
			currCount = 0;
		}
	}
	if (currCount > 0)
	{
		if (currCount % 2 == 0)
		{
			chetnoCount++;
		}
		else
		{
			nechetnoCount++;
		}
	}
	int* result = new int[SIZE];
	result[0] = chetnoCount;
	result[1] = nechetnoCount;

	return result;
}
