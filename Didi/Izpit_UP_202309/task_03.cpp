//MRAZQ Q !!!!!!!!!!!!!!!  

#include <iostream>
#include <bitset>

const int BIT_SIZE = 16;

unsigned short int reverseBitwise(unsigned short int number) {

	unsigned short int bits[BIT_SIZE] = { 0 };


	for (size_t i = 0; i < BIT_SIZE; i++)
	{
		bits[i] = number % 2;
		number /= 2;
	}

    unsigned short int result = 0;
    int multiplier = 1;

    for (size_t i = 0; i < BIT_SIZE; i++)
    {
        result += bits[BIT_SIZE - i - 1] * multiplier;
        multiplier *= 2;
    }

    return result;
}

int main() {
    // Example 1
    unsigned short n1 = 1;
    unsigned short r1 = reverseBitwise(n1);
    std::cout << "Example 1:\n";
    std::cout << "Input:  " << std::bitset<16>(n1) << " (" << n1 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r1) << " (" << r1 << ")\n\n";

    // Example 2
    unsigned short n2 = 32768;
    unsigned short r2 = reverseBitwise(n2);
    std::cout << "Example 2:\n";
    std::cout << "Input:  " << std::bitset<16>(n2) << " (" << n2 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r2) << " (" << r2 << ")\n\n";

    // Example 3
    unsigned short n3 = 61440;
    unsigned short r3 = reverseBitwise(n3);
    std::cout << "Example 3:\n";
    std::cout << "Input:  " << std::bitset<16>(n3) << " (" << n3 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r3) << " (" << r3 << ")\n\n";

    // Example 4
    unsigned short n4 = 12345;
    unsigned short r4 = reverseBitwise(n4);
    std::cout << "Example 4:\n";
    std::cout << "Input:  " << std::bitset<16>(n4) << " (" << n4 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r4) << " (" << r4 << ")\n\n";

    // Example 5
    unsigned short n5 = 0;
    unsigned short r5 = reverseBitwise(n5);
    std::cout << "Example 5:\n";
    std::cout << "Input:  " << std::bitset<16>(n5) << " (" << n5 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r5) << " (" << r5 << ")\n\n";

    // Example 6
    unsigned short n6 = 65535;
    unsigned short r6 = reverseBitwise(n6);
    std::cout << "Example 6:\n";
    std::cout << "Input:  " << std::bitset<16>(n6) << " (" << n6 << ")\n";
    std::cout << "Output: " << std::bitset<16>(r6) << " (" << r6 << ")\n";

    return 0;
}
