#include <iostream>
using namespace std;
bool checkStr(const char* str);
int myCount(const char* str);
const int SIZE = 32;

int main()
{
	// "abxcyba" -> ако махнем 'x' и 'c', остава "abyba" (палиндром) -> true
	cout << "abxcyba -> " << (checkStr("abxcyba") ? "true" : "false") << endl;
	// "abca" -> ако махнем 'b' и 'c', остава "aa" (палиндром) -> true
	cout << "abca -> " << (checkStr("abca") ? "true" : "false") << endl;
	// "abcde" -> няма как да стане палиндром с махане на 2 символа -> false
	cout << "abcde -> " << (checkStr("abcde") ? "true" : "false") << endl;
	cout << endl;
}

bool checkStr(const char* str)
{
	int count = myCount(str);
	if (count <= 3)
	{
		return true;
	}
	for (size_t i = 0; i < count - 1; i++)
	{
		for (size_t j = i + 1; j < count; j++)
		{
			char charTemp[SIZE];
			int tempCount = 0;
			for (size_t k = 0; k < count; k++)
			{
				if (k != i && k != j)
				{
					charTemp[tempCount++] = str[k];
				}
			}
			bool checkPalindrome = true;
			for (size_t left = 0, right = tempCount - 1; left < right; left++, right--)
			{
				if (charTemp[left] != charTemp[right])
				{
					checkPalindrome = false;
					break;
				}
			}

			if (checkPalindrome)
			{
				return true;
			}
		}
	}
	return false;
}

int myCount(const char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
