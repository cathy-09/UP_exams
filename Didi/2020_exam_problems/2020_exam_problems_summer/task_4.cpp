  #include <iostream>

void convertMax(int* arr, int N) {

	if (arr == nullptr || N <= 0) {
		return;
	}

    int max = arr[0];

	for (size_t i = 1; i < N; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	for (size_t i = 0; i < N / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[N - 1 - i];
		arr[N - 1 - i] = temp;
	}

	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] == max) 
		{ 
			continue; 
		}

		arr[i] += max;
	}
}

int main() {
    // Test Case 1: Standard Array
    std::cout << "Test Case 1: Standard Array\n";
    int arr1[] = { 11, 5, 2, 27, 4, 8, 2 };
    std::cout << "Input: arr = {11, 5, 2, 27, 4, 8, 2}\n";

    convertMax(arr1, 7); 

    std::cout << "Actual Output:   arr = {";
    for (int i = 0; i < 7; i++) std::cout << arr1[i] << (i < 6 ? ", " : "");
    std::cout << "}\n";
    std::cout << "Expected Output: arr = {29, 35, 31, 27, 29, 32, 38}\n\n";

    // Test Case 2: Array with Negative Numbers
    std::cout << "Test Case 2: Array with Negative Numbers\n";
    int arr2[] = { -10, -3, -5, -20, -1 };
    std::cout << "Input: arr = {-10, -3, -5, -20, -1}\n";

    convertMax(arr2, 5); 

    std::cout << "Actual Output:   arr = {";
    for (int i = 0; i < 5; i++) std::cout << arr2[i] << (i < 4 ? ", " : "");
    std::cout << "}\n";
    std::cout << "Expected Output: arr = {-1, -21, -6, -4, -11}\n\n";

    // Test Case 3: Single Element Array
    std::cout << "Test Case 3: Single Element Array\n";
    int arr3[] = { 42 };
    std::cout << "Input: arr = {42}\n";

    convertMax(arr3, 1); 

    std::cout << "Actual Output:   arr = {";
    for (int i = 0; i < 1; i++) std::cout << arr3[i] << (i < 0 ? ", " : "");
    std::cout << "}\n";
    std::cout << "Expected Output: arr = {42}\n\n";

    // Test Case 4: All Elements Identical
    std::cout << "Test Case 4: All Elements Identical\n";
    int arr4[] = { 7, 7, 7, 7 };
    std::cout << "Input: arr = {7, 7, 7, 7}\n";

    convertMax(arr4, 4);

    std::cout << "Actual Output:   arr = {";
    for (int i = 0; i < 4; i++) std::cout << arr4[i] << (i < 3 ? ", " : "");
    std::cout << "}\n";
    std::cout << "Expected Output: arr = {7, 7, 7, 7}\n\n";

    // Test Case 5: Maximum Element at the Beginning
    std::cout << "Test Case 5: Maximum Element at the Beginning\n";
    int arr5[] = { 50, 10, 20, 30 };
    std::cout << "Input: arr = {50, 10, 20, 30}\n";

    convertMax(arr5, 4); 

    std::cout << "Actual Output:   arr = {";
    for (int i = 0; i < 4; i++) std::cout << arr5[i] << (i < 3 ? ", " : "");
    std::cout << "}\n";
    std::cout << "Expected Output: arr = {80, 70, 60, 50}\n\n";

    return 0;
}
