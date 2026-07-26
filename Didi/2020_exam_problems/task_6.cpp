//Tiq zadachi sa ebavka za debugera

#include <iostream>

const int SIZE = 2;

char* GetWord(char str[]) {

	if (str == nullptr) {
		return nullptr;
	}

	
	int wordCtr = 0;
	int aWordCtr = 0;

	while (*str != '\0') {
		while (*str == ' ' || *str == '\n' || *str == '\t') {
			str++;
		}
        
        bool isFirstSymbol = true;

        if (*str == '\0') break;

		while (*str != ' ' && *str != '\n' && *str != '\t') {
			if (isFirstSymbol && *str == 'a') {
				aWordCtr++;
			}

            if (*str == '\0') break;

			str++;
            isFirstSymbol = false;
		}

		wordCtr++;
	}

	char* result = new char[SIZE + 1];
	result[0] = aWordCtr;
	result[1] = wordCtr;
    result[2] = '\0';

	return result;
}

int main() {
    // Test 1: Example from the task description
    char test1[] = " It took      about      an hour to                  answer all the questions.               ";
    char* res1 = GetWord(test1);
    std::cout << "Test 1:\n";
    std::cout << "  Input:           \"" << test1 << "\"\n";
    std::cout << "  Expected Output: {4, 10}\n";
    std::cout << "  Actual Output:   {" << (int)res1[0] << ", " << (int)res1[1] << "}\n\n";
    delete[] res1;

    // Test 2: All words start with 'a'
    char test2[] = "always ask about apples";
    char* res2 = GetWord(test2);
    std::cout << "Test 2:\n";
    std::cout << "  Input:           \"" << test2 << "\"\n";
    std::cout << "  Expected Output: {4, 4}\n";
    std::cout << "  Actual Output:   {" << (int)res2[0] << ", " << (int)res2[1] << "}\n\n";
    delete[] res2;

    // Test 3: No words start with 'a'
    char test3[] = "Hello world this is cool";
    char* res3 = GetWord(test3);
    std::cout << "Test 3:\n";
    std::cout << "  Input:           \"" << test3 << "\"\n";
    std::cout << "  Expected Output: {0, 5}\n";
    std::cout << "  Actual Output:   {" << (int)res3[0] << ", " << (int)res3[1] << "}\n\n";
    delete[] res3;

    // Test 4: Mixed tabs, multiple spaces, and case sensitivity ('a' vs 'A')
    char test4[] = "\t  apple  Banana\t  avocado   ALL   ";
    char* res4 = GetWord(test4);
    std::cout << "Test 4:\n";
    std::cout << "  Input:           \"" << test4 << "\"\n";
    std::cout << "  Expected Output: {2, 4}\n";
    std::cout << "  Actual Output:   {" << (int)res4[0] << ", " << (int)res4[1] << "}\n\n";
    delete[] res4;

    // Test 5: Whitespace only
    char test5[] = "   \t   ";
    char* res5 = GetWord(test5);
    std::cout << "Test 5:\n";
    std::cout << "  Input:           \"" << test5 << "\"\n";
    std::cout << "  Expected Output: {0, 0}\n";
    std::cout << "  Actual Output:   {" << (int)res5[0] << ", " << (int)res5[1] << "}\n\n";
    delete[] res5;

    // Test 6: Single word starting with 'a'
    char test6[] = "algorithm";
    char* res6 = GetWord(test6);
    std::cout << "Test 6:\n";
    std::cout << "  Input:           \"" << test6 << "\"\n";
    std::cout << "  Expected Output: {1, 1}\n";
    std::cout << "  Actual Output:   {" << (int)res6[0] << ", " << (int)res6[1] << "}\n";
    delete[] res6;

    return 0;
}
