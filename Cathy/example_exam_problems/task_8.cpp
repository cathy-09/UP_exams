#include <iostream>
using namespace std;
bool CheckDate(char str[]);
const int ARRAY_DATA_COUNT = 5;
int convertStringToNumber(const char* array);
int arrayCount(const char* array);

int main()
{
	char d1[] = "15.08";
	char d2[] = "32.01";
	cout << "\"15.08\" valid? " << (CheckDate(d1) ? "true" : "false") << " (Expected: true)" << endl;
	cout << "\"32.01\" valid? " << (CheckDate(d2) ? "true" : "false") << " (Expected: false)" << endl << endl;
}

bool CheckDate(char str[])
{
	int count = arrayCount(str);
	if (count != ARRAY_DATA_COUNT)
	{
		return false;
	}
	char rezDay[3];
	char rezMonth[3];
	if (str[2] == '.')
	{
		rezDay[0] = str[0];
		rezDay[1] = str[1];
		rezDay[2] = '\0';
		rezMonth[0] = str[3];
		rezMonth[1] = str[4];
		rezMonth[2] = '\0';
		int day = convertStringToNumber(rezDay);
		int month = convertStringToNumber(rezMonth);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day > 31)
			{
				return false;
			}
		}
		else if (month == 2)
		{
			if (day < 1 || day > 29)
			{
				return false;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day > 30)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

int convertStringToNumber(const char* array)
{
	int result = 0;
	while (*array != '\0')
	{
		if (*array >= '0' && *array <= '9')
		{
			result = result * 10 + (*array - '0');
		}
		else
		{
			break;
		}
		array++;
	}
	return result;
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


bool leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}
