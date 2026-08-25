#include <iostream>
using namespace std;
char* GetWord(char str[]);
int myCount(char str[]);
int const SIZE = 256;

int main()
{
	char test1[] = "  C++   is awesome  ";
	char* w1 = GetWord(test1);
	cout << "Test 1 -> " << (w1 ? w1 : "nullptr") << " (Expected: awesome)" << endl;
	delete[] w1;

	char test2[] = "\tHello\tworld";
	char* w2 = GetWord(test2);
	cout << "Test 2 -> " << (w2 ? w2 : "nullptr") << " (Expected: Hello)" << endl;
	delete[] w2;

	return 0;
}

char* GetWord(char str[])
{
	if (str == nullptr)
	{
		return nullptr;
	}
	int max = 0;
	int currMax = 0;
	int maxIndex = 0;
	int currIndex = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			if (currMax == 0)
			{
				currIndex = i;
			}
			currMax++;
		}
		else
		{
			if (currMax > max)
			{
				max = currMax;
				maxIndex = currIndex;
			}
			currMax = 0;
		}

	}
	if (currMax > max)
	{
		max = currMax;
		maxIndex = currIndex;
	}
	char* array = new char[max + 1];
	for (int i = 0; i < max; i++)
	{
		array[i] = str[maxIndex + i];;
	}
	array[max] = '\0';
	return array;
}

int myCount(char str[])
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
