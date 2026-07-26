#include <iostream>

const int SIZE = 7;

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

bool isNumber(char c) {
	return c >= '0' && c <= '9';
}

int charToNum(char c) {
	return c - '0';
}

bool CheckDate(char str[]) {
	//"YYYY g."

	if (str == nullptr) {
		return false;
	}

	int length = getLen(str);

	if (length != SIZE) {
		return false;
	}

	if (str[4] != ' ' || str[5] != 'g' || str[6] != '.') {
		return false;
	}

	int year = 0;
	int multipier = 1000;

	for (size_t i = 0; i < SIZE - 3; i++)
	{
		if (!isNumber(str[i])) {
			return false;
		}

		year = year + multipier * charToNum(str[i]);
		multipier /= 10;
	}

	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	// Print booleans as 'true' or 'false' instead of 1 or 0
	std::cout << std::boolalpha;

	// Direct test cases (char arrays used to match non-const char[] signature)
	char t1[] = "2024 g.";
	char t2[] = "2000 g.";
	char t3[] = "1900 g.";
	char t4[] = "2023 g.";
	char t5[] = "2024g.";
	char t6[] = "2024 g";
	char t7[] = "ABCD g.";

	// Simple prints showing Input, Expected, and Actual Output
	std::cout << "Input: \"" << t1 << "\" | Expected: true  | Output: " << CheckDate(t1) << "\n";
	std::cout << "Input: \"" << t2 << "\" | Expected: true  | Output: " << CheckDate(t2) << "\n";
	std::cout << "Input: \"" << t3 << "\" | Expected: false | Output: " << CheckDate(t3) << "\n";
	std::cout << "Input: \"" << t4 << "\" | Expected: false | Output: " << CheckDate(t4) << "\n";
	std::cout << "Input: \"" << t5 << "\" | Expected: false | Output: " << CheckDate(t5) << "\n";
	std::cout << "Input: \"" << t6 << "\" | Expected: false | Output: " << CheckDate(t6) << "\n";
	std::cout << "Input: \"" << t7 << "\" | Expected: false | Output: " << CheckDate(t7) << "\n";

	return 0;
}
