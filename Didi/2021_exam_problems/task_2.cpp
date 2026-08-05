#include <iostream>

int getLen(long num) {

    if (num == 0) {
        return 0;
    }

    int len = 0;

    while (num != 0) {
        len++;
        num /= 10;
    }

    return len;
}

int* convertNum(long num, int k, int m) {

    int length = getLen(num);

    if (k < 1 || m < 1 || k > length || m > length) {
        return nullptr;
    }

    int* digits = new int[length];

    for (size_t i = 0; i < length; i++)
    {
        digits[length - 1 - i] = num % 10;
        num /= 10;
    }

    int temp = digits[k - 1];
    digits[k - 1] = digits[m - 1];
    digits[m - 1] = temp;

    return digits;
}

int main() {
    // Test 1: First example from the description
    long num1 = 123456789;
    int k1 = 3, m1 = 5;
    int size1 = 9;
    int* res1 = convertNum(num1, k1, m1);

    std::cout << "Test 1: num = " << num1 << ", k = " << k1 << ", m = " << m1 << "\n";
    std::cout << "Expected result: 1 2 5 4 3 6 7 8 9\n";
    std::cout << "Actual result:   ";
    for (int i = 0; i < size1; ++i) {
        std::cout << res1[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res1;

    // Test 2: Second example from the description
    long num2 = 437263;
    int k2 = 4, m2 = 1;
    int size2 = 6;
    int* res2 = convertNum(num2, k2, m2);

    std::cout << "Test 2: num = " << num2 << ", k = " << k2 << ", m = " << m2 << "\n";
    std::cout << "Expected result: 2 3 7 4 6 3\n";
    std::cout << "Actual result:   ";
    for (int i = 0; i < size2; ++i) {
        std::cout << res2[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res2;

    // Test 3: Swapping first and last digits
    long num3 = 9876;
    int k3 = 1, m3 = 4;
    int size3 = 4;
    int* res3 = convertNum(num3, k3, m3);

    std::cout << "Test 3: num = " << num3 << ", k = " << k3 << ", m = " << m3 << "\n";
    std::cout << "Expected result: 6 8 7 9\n";
    std::cout << "Actual result:   ";
    for (int i = 0; i < size3; ++i) {
        std::cout << res3[i] << " ";
    }
    std::cout << "\n\n";
    delete[] res3;

    // Test 4: Swapping the exact same positions (k = m)
    long num4 = 512;
    int k4 = 2, m4 = 2;
    int size4 = 3;
    int* res4 = convertNum(num4, k4, m4);

    std::cout << "Test 4: num = " << num4 << ", k = " << k4 << ", m = " << m4 << "\n";
    std::cout << "Expected result: 5 1 2\n";
    std::cout << "Actual result:   ";
    for (int i = 0; i < size4; ++i) {
        std::cout << res4[i] << " ";
    }
    std::cout << "\n";
    delete[] res4;

    return 0;
}
