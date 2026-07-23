#include <iostream>
using namespace std;
int* revArr(int* arr, int len, int k);

int main()
{
    int rArr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int* revRes = revArr(rArr, 8, 3);
    cout << "(k=3) { 1..8 } -> { ";
    for (int i = 0; i < 8; i++) cout << revRes[i] << (i < 7 ? ", " : " ");
    cout << "} (Expected: 8, 7, 6, 5, 4, 3, 1, 2)" << endl;
    delete[] revRes;
    cout << endl;
}

int* revArr(int* arr, int len, int k)
{
    if (arr == nullptr || len <= 0)
    {
        return nullptr;
    }
    int* result = new int[len];
    int index = k - 1; 
    if (index < 0)
    {
        index = 0;
    }
    if (index >= len)
    {
        index = len - 1;
    }
    int j = 0;
    for (int i = len - 1; i >= index; i--)
    {
        result[j] = arr[i];
        j++;
    }
    for (size_t i = 0; i < index; i++)
    {
        result[j] = arr[i];
        j++;
    }
    return result;
}
