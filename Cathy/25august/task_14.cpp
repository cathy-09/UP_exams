#include <iostream>
using namespace std;
int maxWord(char* str);

int main()
{
	char mw1[] = "This is a string";
	char mw2[] = "This is aNothEr string";
	cout << "\"This is a string\" -> " << maxWord(mw1) << " (Expected: 36)" << endl;
	cout << "\"This is aNothEr string\" -> " << maxWord(mw2) << " (Expected: 35)" << endl << endl;
}

int maxWord(char* str)
{
	if (str == nullptr)
	{
		return 0;
	}
	int maxLen = 0;
	int currLen = 0;
	int maxCount = 0;
	int currCount = 0;
	for (size_t i = 0; ; i++)
	{
		char charche = str[i];
		if (!(charche == ' ' || charche == '\t' || charche == '\0'))
		{
			currLen++;
			if (charche >= 'a' && charche <= 'z')
			{
				currCount++;
			}
		}
		else
		{
			if (currLen > 0)
			{
				if (currLen > maxLen)
				{
					maxLen = currLen;
					maxCount = currCount;
				}
				currLen = 0;
				currCount = 0;
			}
		}

		if (charche == '\0')
		{
			break;
		}
	}
	return maxCount * maxLen;
}
