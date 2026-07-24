#include <iostream>
using namespace std;
int findNumber(const char* str);
const int SIZE = 32;

int main()
{
    cout << "(a3b7c3d -> 373): " << findNumber("a3b7c3d") << endl;
    cout << "(code12 -> -1): " << findNumber("code12") << endl;
    cout << "(x1y2z3 -> -1): " << findNumber("x1y2z3") << endl;
    cout << "(abc5def5gh5 -> 555): " << findNumber("abc5def5gh5") << endl;
    cout << endl;
}

int findNumber(const char* str)
{
    int numbers[SIZE];
    int count = 0;
    int index = 0;
    while (str[index] != '\0')
    {
        if (str[index] >= '0' && str[index] <= '9')
        {
            numbers[count++] = str[index] - '0';
        }
        index++;
    }
    if (count != 3)
    {
        return -1;
    }

    if (numbers[0] == numbers[1])
    {
        return numbers[0] * 100 + numbers[2] * 10 + numbers[0];
    }
    if (numbers[0] == numbers[2])
    {
        return numbers[0] * 100 + numbers[1] * 10 + numbers[0];
    }
    if (numbers[1] == numbers[2])
    {
        return numbers[1] * 100 + numbers[0] * 10 + numbers[1];
    }
    return -1;
}

