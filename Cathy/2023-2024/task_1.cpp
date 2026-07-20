#include <iostream>
using namespace std;
bool analyzeArr(const char* array);
int arrayCount(const char* array);
bool toUpper(const char charche);
char toLowerT(const char charche);

int main()
{
	cout << analyzeArr("AaBbCc") << endl;                 // true
	cout << analyzeArr("ABCabcXYZxyz") << endl;           // true
	cout << analyzeArr("ABCabcX") << endl;                // true //ammmmmm geminiiiiiiiiii
	cout << analyzeArr("ABCxyz") << endl;                 // false (X,Y,Z немаат мали)
	cout << analyzeArr("Hello") << endl;                  // false (H нема h)
	cout << analyzeArr("aAbBcCdD") << endl;               // true
	cout << analyzeArr("ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl; // false
	cout << analyzeArr("abcdefghijklmnopqrstuvwxyz") << endl; // true
	cout << analyzeArr("") << endl;                       // true
}

bool analyzeArr(const char* array)
{
	int count = arrayCount(array);
	if (array[0] == '\0')
	{
		return true;
	}
	for (size_t i = 0; i < count; i++)
	{
		if (toUpper(array[i]))
		{
			char smallCharacter = toLowerT(array[i]);
			bool flag = false;
			for (size_t j = 0; j < count; j++)
			{
				if (array[j] == smallCharacter)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				return false;
			}
		}
	}
	return true;
}

int arrayCount(const char* array)
{
	int count = 0;
	while (*array != '\0')
	{
		count++;
		array++;
	}
	return count;
}

bool toUpper(const char charche)
{
	if (charche >= 'A' && charche <= 'Z')
	{
		return true;
	}
}

char toLowerT(const char charche)
{
	if (charche >= 'A' && charche <= 'Z')
	{
		return charche + ('a' - 'A');
	}
	return charche;
}
