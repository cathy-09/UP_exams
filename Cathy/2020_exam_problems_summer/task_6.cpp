#include <iostream>
using namespace std;
long convertNumber(char* num);
void BubbleSort(int* arr, size_t len);
int myCount(char array[]);

int main()
{
    char strAscii[] = "abcZ"; // ASCII: 'a'=97, 'b'=98, 'c'=99, 'Z'=90 -> max 3: 99+98+97 = 294
    cout << "\"abcZ\" top 3 ASCII sum: " << convertNumber(strAscii) << " (Expected: 294)" << endl << endl;
}

long convertNumber(char* num)
{
    if (num == nullptr)
    {
        return 0;
    }
    int count = myCount(num);
    if (count == 0)
    {
        return 0;
    }
    int* ASCIIcodes = new int[count];
    for (size_t i = 0; i < count; i++)
    {
        ASCIIcodes[i] = num[i];
    }   
    BubbleSort(ASCIIcodes, count);
    int sum = 0;
    int temp = 0;
    if (count < 3)
    {
        temp = count;
    }
    else
    {
        temp = 3;
    }
    for (size_t i = 0; i < temp; i++)
    {
        sum = sum + ASCIIcodes[i];
    }
    delete[] ASCIIcodes;
    return sum;
}

void BubbleSort(int* arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int myCount(char array[])
{
    int count = 0;
    while (*array != '\0')
    {
        count++;
        array++;
    }
    return count;
}
