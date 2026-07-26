#include <iostream>

void mySwap(char& first, char& second) {
	char temp = first;
	first = second;
	second = temp;
}

int getLen(char* input) {
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

char* revandreplace(char* input) {

	if (input == nullptr) {
		return nullptr;
	}

	int length = getLen(input);

	for (size_t i = 0; i < length / 2; i++)
	{
		mySwap(input[i], input[length - i - 1]);
	}

	for (size_t i = 0; i < length; i++)
	{
		if (input[i] == 'e') {
			input[i] = '!';
		}
		else if (input[i] == 'y') {
			input[i] = '*';
		}
	}

	return input;
}

int main()
{
	char str[] = "I left you alone"; 
	std::cout << revandreplace(str);
}
