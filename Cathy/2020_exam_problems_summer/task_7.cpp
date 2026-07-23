#include <iostream>
using namespace std;
long convertNumber(char* num);

int main()
{
    char dStr1[] = "123";  // '1'(49) + '2'(50) + '3'(51) = 150
    char dStr2[] = "12a3"; // Invalid
    cout << "\"123\" digits sum: " << convertNumber(dStr1) << " (Expected: 150)" << endl;
    cout << "\"12a3\" digits sum: " << convertNumber(dStr2) << " (Expected: -1)" << endl << endl;
}

long convertNumber(char* num)
{
    if (num == nullptr || num[0] == '\0')
    {
        return -1;
    }
    int sum = 0;
    for (size_t i = 0; num[i] != '\0'; i++)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            return -1;
        }
        sum = sum + num[i];
    }
    return sum;
}
