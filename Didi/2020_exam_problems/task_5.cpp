#include <iostream>

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLetter(char c) {
    return isUppercase(c) || isLowercase(c);
}

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

bool checkstr(char* str) {

	int length = getLen(str);

	if (length == 0) {
		return true;
	}

	if (length == 1) {
		return isLetter(*str);
	}

	for (size_t i = 0; i < length - 1; i++)
	{
		if (!isLetter(str[i])) {
			return false;
		}

		if (isLowercase(str[i])) {
			if (!isUppercase(str[i + 1])) {
				return false;
			}
		}
		if (isUppercase(str[i])) {
			 if (!isLowercase(str[i + 1])) {
				 return false;
			 }
		}
	}

	return true;
}

int main() {
	struct TestCase {
		char input[50];
		bool expected;
	};

	TestCase tests[] = {
		{"aZaAaCfEa", true},
		{"bAzCBaFbK", false},
		{"bAzC$aFbK", false},
		{"ZaZaZ",     true},
		{"a",         true},
		{"A",         true},
		{"aB",        true},
		{"Ab",        true},
		{"a1B",       false},
		{"",          true}
	};

	int numTests = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < numTests; ++i) {
		std::cout << "Test " << (i + 1) << ":\n";
		std::cout << "  Input:    \"" << tests[i].input << "\"\n";
		std::cout << "  Expected: " << (tests[i].expected ? "true" : "false") << "\n";
		std::cout << "  Actual:   " << (checkstr(tests[i].input) ? "true" : "false") << "\n";
		std::cout << "-------------------------------\n";
	}

	return 0;
}
