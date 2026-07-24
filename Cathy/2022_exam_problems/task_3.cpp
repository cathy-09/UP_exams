#include <iostream>
using namespace std;
unsigned int getGCD(const unsigned int* arr, size_t size);
unsigned int gcdTwoNumbers(unsigned int a, unsigned int b);

int main()
{
    unsigned int arr1_1[] = { 12, 18, 24 };
    cout << getGCD(arr1_1, 3) << endl;

    unsigned int arr1_2[] = { 7, 14, 25 };
    cout << getGCD(arr1_2, 3) << endl;

    unsigned int arr1_3[] = { 42 };
    cout << getGCD(arr1_3, 1) << endl;

    unsigned int arr1_4[] = { 0, 15, 30 };
    cout << getGCD(arr1_4, 3) << endl;

    cout << endl;
}

unsigned int getGCD(const unsigned int* arr, size_t size)
{
    if (size == 0)
    {
        return 0;
    }
    unsigned int currGCD = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        currGCD = gcdTwoNumbers(currGCD, arr[i]);
    }
    return currGCD;
}

unsigned int gcdTwoNumbers(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
