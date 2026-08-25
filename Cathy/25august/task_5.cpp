#include <iostream>
char* GetWord(char str[]);
int myCount(char str[]);
int const SIZE = 2;

int main()
{
	// Тест 1: Стандартен изреченски низ с няколко думи на 'a'
	char test1[] = "apple banana avocado orange apricot";
	char* rawRes1 = GetWord(test1);
	int* res1 = (int*)rawRes1;
	std::cout << "Test 1 (\"apple banana avocado orange apricot\"):\n";
	if (res1) {
		std::cout << "  - Words starting with 'a': " << res1[0] << " (Expected: 3)\n";
		std::cout << "  - Total words: " << res1[1] << " (Expected: 5)\n";
		delete[] rawRes1; // Освобождаване на динамично заделената памет
	}
	else {
		std::cout << "  - Returned nullptr!\n";
	}

	// Тест 2: Низ с интервали, табулации и главна/малка буква 'a'
	char test2[] = "\t  an  apple \t a day   ";
	char* rawRes2 = GetWord(test2);
	int* res2 = (int*)rawRes2;
	std::cout << "\nTest 2 (\"\\t  an  apple \\t a day   \"):\n";
	if (res2) {
		std::cout << "  - Words starting with 'a': " << res2[0] << " (Expected: 3)\n";
		std::cout << "  - Total words: " << res2[1] << " (Expected: 4)\n";
		delete[] rawRes2;
	}
	else {
		std::cout << "  - Returned nullptr!\n";
	}

	// Тест 3: Низ без думи, започващи с 'a'
	char test3[] = "hello world test C++";
	char* rawRes3 = GetWord(test3);
	int* res3 = (int*)rawRes3;
	std::cout << "\nTest 3 (\"hello world test C++\"):\n";
	if (res3) {
		std::cout << "  - Words starting with 'a': " << res3[0] << " (Expected: 0)\n";
		std::cout << "  - Total words: " << res3[1] << " (Expected: 4)\n";
		delete[] rawRes3;
	}
	else {
		std::cout << "  - Returned nullptr!\n";
	}

	// Тест 4: Празен низ
	char test4[] = "";
	char* rawRes4 = GetWord(test4);
	int* res4 = (int*)rawRes4;
	std::cout << "\nTest 4 (\"\"):\n";
	if (res4) {
		std::cout << "  - Words starting with 'a': " << res4[0] << " (Expected: 0)\n";
		std::cout << "  - Total words: " << res4[1] << " (Expected: 0)\n";
		delete[] rawRes4;
	}
	else {
		std::cout << "  - Returned nullptr!\n";
	}

	// Тест 5: Невалиден вход (nullptr)
	char* rawRes5 = GetWord(nullptr);
	std::cout << "\nTest 5 (nullptr):\n";
	std::cout << "  - Expected nullptr, Got: " << (rawRes5 ? "valid pointer" : "nullptr") << std::endl;
	delete[] rawRes5;

	return 0;
}

char* GetWord(char str[])
{
	if (str == nullptr)
	{
		return nullptr;
	}
	int wordCount = 0;
	int wordCountA = 0;
	int startWord = 0;
	bool inWord = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			if (!inWord)
			{
				inWord = true;
				wordCount++;
				if (str[i] == 'a')
				{
					wordCountA++;
				}
			}

		}
		else
		{
			inWord = false;
		}
	}
	int* array = new int[SIZE];
	array[0] = wordCountA;
	array[1] = wordCount;
	return (char*)array;
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
