#include <iostream>
bool doExist(char* symbols, char* word);
int myCount(char str[]);

int main()
{
	// Тест 1: Валидно съвпадение (symbols наобратно е "dlrow olleh", съдържа "olleh")
	char test1_symbols[] = "hello world";
	char test1_word[] = "olleh";
	std::cout << "Test 1 (\"hello world\", \"olleh\"): Expected 1, Got "
		<< doExist(test1_symbols, test1_word) << std::endl;

	// Тест 2: Търсената дума НЕ се среща в обърнатия низ
	char test2_symbols[] = "hello world";
	char test2_word[] = "world";
	std::cout << "Test 2 (\"hello world\", \"world\"): Expected 0, Got "
		<< doExist(test2_symbols, test2_word) << std::endl;

	// Тест 3: Търсената дума съвпада с целия обърнат низ ("abcd" -> "dcba")
	char test3_symbols[] = "abcd";
	char test3_word[] = "dcba";
	std::cout << "Test 3 (\"abcd\", \"dcba\"): Expected 1, Got "
		<< doExist(test3_symbols, test3_word) << std::endl;

	// Тест 4: Празен word (всеки низ съдържа празния низ)
	char test4_symbols[] = "abc";
	char test4_word[] = "";
	std::cout << "Test 4 (\"abc\", \"\"): Expected 1, Got "
		<< doExist(test4_symbols, test4_word) << std::endl;

	// Тест 5: word е по-дълъг от symbols
	char test5_symbols[] = "ab";
	char test5_word[] = "cba";
	std::cout << "Test 5 (\"ab\", \"cba\"): Expected 0, Got "
		<< doExist(test5_symbols, test5_word) << std::endl;

	// Тест 6: Невалидни входни данни (nullptr)
	std::cout << "Test 6 (nullptr, \"abc\"): Expected 0, Got "
		<< doExist(nullptr, test5_word) << std::endl;

	return 0;
}

bool doExist(char* symbols, char* word)
{
	if (symbols == nullptr)
	{
		return false;
	}
	if (word == nullptr)
	{
		return false;
	}
	int symbolsCount = myCount(symbols);
	int wordCount = myCount(word);
	if (wordCount == 0)
	{
		return true;
	}
	if (symbolsCount < wordCount)
	{
		return false;
	}
	int count = 0;
	for (int i = symbolsCount - 1; i >= wordCount - 1; i--)
	{
		for (size_t j = 0; j < wordCount; j++)
		{
			if (symbols[i - j] == word[j])
			{
				count++;
			}
			else
			{
				count = 0;
				break;
			}
		}
		if (count == wordCount)
		{
			return true;
		}
		else
		{
			count = 0;
		}
	}
	return false;
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
