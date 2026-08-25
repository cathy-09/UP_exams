#include <iostream>
int CheckStr(char str[]);
int myCount(char str[]);
int const SIZE = 256;

int main() {
	// Тест 1: Валиден палиндром с нечетна дължина ("beblehl" -> "belhleb")
	char test1[] = "beblehl";
	std::cout << "Test 1 (\"beblehl\"): Expected 1, Got " << CheckStr(test1) << std::endl;

	// Тест 2: Валиден палиндром с четна дължина ("aabb" -> "abba")
	char test2[] = "aabb";
	std::cout << "Test 2 (\"aabb\"): Expected 1, Got " << CheckStr(test2) << std::endl;

	// Тест 3: Невъзможно пренареждане до палиндром
	char test3[] = "asdfgjk";
	std::cout << "Test 3 (\"asdfgjk\"): Expected 0, Got " << CheckStr(test3) << std::endl;

	// Тест 4: Невалиден вход - празен низ (дължина 0 < 2)
	char test4[] = "";
	std::cout << "Test 4 (\"\"): Expected -1, Got " << CheckStr(test4) << std::endl;

	// Тест 5: Невалиден вход - само 1 символ (дължина 1 < 2)
	char test5[] = "a";
	std::cout << "Test 5 (\"a\"): Expected -1, Got " << CheckStr(test5) << std::endl;

	// Тест 6: Минимална валидна дължина от 2 еднакви символа ("aa")
	char test6[] = "aa";
	std::cout << "Test 6 (\"aa\"): Expected 1, Got " << CheckStr(test6) << std::endl;

	// Тест 7: Невалиден вход - NULL указател
	std::cout << "Test 7 (NULL): Expected -1, Got " << CheckStr(nullptr) << std::endl;

	return 0;
}

int CheckStr(char str[])
{
	if (str == nullptr)
	{
		return -1;
	}
	int count = myCount(str);
	if (count < 2)
	{
		return -1;
	}
	int unique[SIZE] = { 0 };
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		char charche = str[i];
		unique[charche]++;
	}
	int odd = 0;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (unique[i] % 2 != 0)
		{
			odd++;
		}
	}
	if (odd <= 1)
	{
		return 1;
	}
	return 0;
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
