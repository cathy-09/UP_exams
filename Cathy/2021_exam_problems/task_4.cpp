#include <iostream>
using namespace std;
int* mergeArr(int* arr1, int* arr2, int len);

int main()
{
    int mArr1[] = { 1, 11, 3, 99, 5 };
    int mArr2[] = { 4, 2, 23, 0, 7 };
    int* mRes1 = mergeArr(mArr1, mArr2, 5);
    cout << "Result 1: { ";
    for (int i = 0; i < 5; i++) cout << mRes1[i] << (i < 4 ? ", " : " ");
    cout << "} (Expected: 0, 2, 0, -1, 2)" << endl;
    delete[] mRes1;
}

int* mergeArr(int* arr1, int* arr2, int len)
{
    if (arr1 == nullptr || arr2 == nullptr || len <= 0)
    {
        return nullptr;
    }
    int* result = new int[len];
    for (size_t i = 0; i < len; i++)
    {
        int cel = arr1[i];
        int found = -1;
        for (size_t j = 0; j < len; j++)
        {
            if (arr2[j] > cel)
            {
                found = j;
                break; 
            }
        }
        result[i] = found;
    }
    return result;
}
