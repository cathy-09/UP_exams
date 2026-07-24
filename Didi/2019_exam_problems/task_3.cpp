#include <iostream>

void ConvertNum(long& num) {
    long copyNum = num;
    long result = 0;

    while (copyNum != 0) {
        result = result * 10 + copyNum % 10;
        copyNum /= 10;
    }

    num = result;
}

int main()
{
    long n1 = 12345; ConvertNum(n1); std::cout << "12345 -> " << n1 << " (54321)" << std::endl;
    long n2 = -456; ConvertNum(n2); std::cout << "-456 -> " << n2 << " (-654)" << std::endl;
    long n3 = 1500; ConvertNum(n3); std::cout << "1500 -> " << n3 << " (51)" << std::endl;
    long n4 = 0; ConvertNum(n4); std::cout << "0 -> " << n4 << " (0)" << std::endl;
    long n5 = 7; ConvertNum(n5); std::cout << "7 -> " << n5 << " (7)" << std::endl;
    long n6 = 1221; ConvertNum(n6); std::cout << "1221 -> " << n6 << " (1221)" << std::endl;
    long n7 = 123456789; ConvertNum(n7); std::cout << "123456789 -> " << n7 << " (987654321)" << std::endl;
}
