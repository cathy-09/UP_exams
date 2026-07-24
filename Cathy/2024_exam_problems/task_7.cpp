//NOVA
#include <iostream>
using namespace std;
int convert(const char* str, int k);

int main()
{
    cout << "convert(\"10110\", 2) -> " << convert("10110", 2)
        << " (Expected: 22)" << endl << endl;

    cout << "convert(\"1A3F\", 16) -> " << convert("1A3F", 16)
        << " (Expected: 6719)" << endl;
    cout << "convert(\"1a3f\", 16) -> " << convert("1a3f", 16)
        << " (Expected: 6719)" << endl << endl;

    cout << "convert(\"755\", 8) -> " << convert("755", 8)
        << " (Expected: 493)" << endl << endl;

    cout << "convert(\"Z1\", 36) -> " << convert("Z1", 36)
        << " (Expected: 1261)" << endl; // 35 * 36 + 1 = 1261
}

int convert(const char* str, int k)
{
    if (str == nullptr || k < 2 || k > 36)
    {
        return 0;
    }
    int result = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char charche = str[i];
        int value = -1;
        if (charche >= '0' && charche <= '9')
        {
            value = charche - '0';
        }
        else if (charche >= 'a' && charche <= 'z')
        {
            value = charche - 'a' + 10;
        }
        else if (charche >= 'A' && charche <= 'Z')
        {
            value = charche - 'A' + 10;
        }
        result = result * k + value;
    }
    return result;
}
