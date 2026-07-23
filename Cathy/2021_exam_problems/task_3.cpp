#include <iostream>
using namespace std;
int* newArr(int* arr, int len);

int main()
{
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int* nArrRes = newArr(a1, 8);
    cout << "{ 1, 2, 3, 4, 5, 6, 7, 8 } -> { ";
    for (int i = 0; i < 4; i++) cout << nArrRes[i] << (i < 3 ? ", " : " ");
    cout << "} (Expected: 6, 8, 10, 12)" << endl;
    delete[] nArrRes;
    cout << endl;
}

int* newArr(int* arr, int len)
{
    if (arr == nullptr || len <= 0)
    {
        return nullptr;
    }
    int sum = 0;
    int average = 0;
    int even = 0;
    for (size_t i = 0; i < len; i++)
    {
        sum = sum + arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
        }
    }
    average = sum / len;
    int* result = new int[even];
    int index = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            result[index] = arr[i] + average;
            index++;
        }
    }
    return result;
}
