#include <iostream>

const int SIZE = 2;

bool isLowercase(int c) {
	return c >= 'a' && c <= 'z';
}

bool isUppercase(int c) {
	return c >= 'A' && c <= 'Z';
}

int* countletters(int first[], int second[], int N) {

	if (first == nullptr && second == nullptr || N < 0) {
		return nullptr;
	}

	int* result = new int[SIZE];
	
	int lowercaseCtr = 0;
	int uppercaseCtr = 0;

	for (size_t i = 0; i < N; i++)
	{
		int sum = 0;

		if (first == nullptr) {
			sum = second[i];
		}
		else if (second == nullptr) {
			sum = first[i];
		}
		else {
			sum = first[i] + second[i];
		}

		if (isUppercase(sum)) {
			uppercaseCtr++;
		}
		else if (isLowercase(sum)) {
			lowercaseCtr++;
		}
	}

	result[0] = uppercaseCtr;
	result[1] = lowercaseCtr;

	return result;
}

int main() {
    // Test Case 1: Example from prompt
    int a1[] = { 3, 5, 11, 2, 9 };
    int b1[] = { 1, 4, 32, 71, 5 };
    int n1 = 5;
    int* res1 = countletters(a1, b1, n1);

    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Input Array 1: {3, 5, 11, 2, 9}" << std::endl;
    std::cout << "Input Array 2: {1, 4, 32, 71, 5}" << std::endl;
    std::cout << "N: 5" << std::endl;
    std::cout << "Expected Output: {1, 0}" << std::endl;
    std::cout << "Actual Output:   {" << res1[0] << ", " << res1[1] << "}" << std::endl;
    delete[] res1;
    std::cout << std::endl;

    // Test Case 2: Lowercase boundary test ('a' = 97, 'z' = 122)
    int a2[] = { 50, 60, 61 };
    int b2[] = { 47, 37, 61 };
    int n2 = 3;
    int* res2 = countletters(a2, b2, n2);

    std::cout << "Test Case 2:" << std::endl;
    std::cout << "Input Array 1: {50, 60, 61}" << std::endl;
    std::cout << "Input Array 2: {47, 37, 61}" << std::endl;
    std::cout << "N: 3" << std::endl;
    std::cout << "Expected Output: {0, 3}" << std::endl;
    std::cout << "Actual Output:   {" << res2[0] << ", " << res2[1] << "}" << std::endl;
    delete[] res2;
    std::cout << std::endl;

    // Test Case 3: Mixed upper ('A', 'Z') and lower ('a') with negative values
    int a3[] = { 30, 45, 50, 100, 0 };
    int b3[] = { 35, 45, 47, -3, 10 };
    int n3 = 5;
    int* res3 = countletters(a3, b3, n3);

    std::cout << "Test Case 3:" << std::endl;
    std::cout << "Input Array 1: {30, 45, 50, 100, 0}" << std::endl;
    std::cout << "Input Array 2: {35, 45, 47, -3, 10}" << std::endl;
    std::cout << "N: 5" << std::endl;
    std::cout << "Expected Output: {2, 2}" << std::endl;
    std::cout << "Actual Output:   {" << res3[0] << ", " << res3[1] << "}" << std::endl;
    delete[] res3;
    std::cout << std::endl;

    // Test Case 4: Non-letter ASCII boundaries (64, 91, 96, 123)
    int a4[] = { 10, 64, 91, 96, 123 };
    int b4[] = { 20, 0, 0, 0, 0 };
    int n4 = 5;
    int* res4 = countletters(a4, b4, n4);

    std::cout << "Test Case 4:" << std::endl;
    std::cout << "Input Array 1: {10, 64, 91, 96, 123}" << std::endl;
    std::cout << "Input Array 2: {20, 0, 0, 0, 0}" << std::endl;
    std::cout << "N: 5" << std::endl;
    std::cout << "Expected Output: {0, 0}" << std::endl;
    std::cout << "Actual Output:   {" << res4[0] << ", " << res4[1] << "}" << std::endl;
    delete[] res4;

    return 0;
}
