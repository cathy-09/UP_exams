#include <iostream>

const int ALPHEBET_SIZE = 26;

int getLen(const char* input) {
	int len = 0;

	if (input == nullptr) {
		return 0;
	}

	while (*input != '\0') {
		len++;
		input++;
	}

	return len;
}

bool isUpperCase(char c) {
	return c >= 'A' && c <= 'Z';
}

bool isLowerCase(char c) {
	return c >= 'a' && c <= 'z';
}

bool analyzeArr(const char* input) {
	int uppercase[ALPHEBET_SIZE] = { 0 };
	int lowercase[ALPHEBET_SIZE] = { 0 };

	bool isTrue = true;
	int len = getLen(input);

	for (size_t i = 0; i < len; i++)
	{
		if (isUpperCase(input[i])) {
			int index = input[i] - 'A';
			uppercase[index] = 1;
			continue;
		}

		if (isLowerCase(input[i])) {
			int index = input[i] - 'a';
			lowercase[index] = 1;
			continue;
		}
	}

	for (size_t i = 0; i < ALPHEBET_SIZE; i++)
	{
		if (uppercase[i] == 1) {
			if (lowercase[i] != 1) {
				isTrue = false;
				break;
			}
		}
	}

	return isTrue;
}

int main()
{
	const char* input = "AKss1.UkS02uatA";
	std::cout << analyzeArr(input);
}
