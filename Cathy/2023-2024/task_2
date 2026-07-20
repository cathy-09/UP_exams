#include <iostream>
using namespace std;
bool validDate(const char* array);
int convertStringToNumber(const char* array);
int arrayCount(const char* array);
bool leap(int year);
const int ARRAY_DATA_COUNT = 10;

int main()
{
	cout << validDate("01-01-2024") << endl; // true
	cout << validDate("29-02-2024") << endl; // true
	cout << validDate("29-02-2023") << endl; // false
	cout << validDate("31-04-2024") << endl; // false
	cout << validDate("30-04-2024") << endl; // true
	cout << validDate("31-12-1999") << endl; // true
	cout << validDate("00-01-2024") << endl; // false
	cout << validDate("15-13-2024") << endl; // false
	cout << validDate("32-01-2024") << endl; // false
	cout << validDate("1-1-2024") << endl;   // false
	cout << validDate("15/08/2024") << endl; // false
}

bool validDate(const char* array)
{
	int count = arrayCount(array);
	if (count != ARRAY_DATA_COUNT)
	{
		return false;
	}
	char rezDay[3];
	char rezMonth[3];
	char rezYear[5];
	if (array[2] == '-' && array[5] == '-')
	{
		rezDay[0] = array[0];
		rezDay[1] = array[1];
		rezDay[2] = '\0';
		rezMonth[0] = array[3];
		rezMonth[1] = array[4];
		rezMonth[2] = '\0';
		rezYear[0] = array[6];
		rezYear[1] = array[7];
		rezYear[2] = array[8];
		rezYear[3] = array[9];
		rezYear[4] = '\0';
		int day = convertStringToNumber(rezDay);
		int month = convertStringToNumber(rezMonth);
		int year = convertStringToNumber(rezYear);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day > 31)
			{
				return false;
			}
		}
		else if (month == 2)
		{
			if (leap(year))
			{
				if (day < 1 || day > 29)
				{
					return false;
				}
			}
			else
			{
				if (day < 1 || day > 28)
				{
					return false;
				}
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
		if (year <= 0)
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
