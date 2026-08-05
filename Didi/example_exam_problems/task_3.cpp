#include <iostream>

void printRectangle(int n, int m, char symbol) {

	if (n <= 0 || m <= 0 || n > 25 || m > 80) {
		std::cout << "Invalid numbers!" << std::endl;
		return;
	}

	for (size_t i = 0; i < (25 - n) / 2; i++)
	{
		std::cout << std::endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t spaces = 0; spaces < (80 - m) / 2; spaces++)
		{
			std::cout << " ";
		}

		for (size_t j = 0; j < m; j++)
		{
			std::cout << symbol;
		}

		std::cout << std::endl;
	}

	for (size_t i = 0; i < (25 - n) / 2; i++)
	{
		std::cout << std::endl;
	}
}

int main() {

	printRectangle(11, 50, '*');
}
