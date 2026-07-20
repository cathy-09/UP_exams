#include <iostream>
using namespace std;
int* findSets(const int arr[], size_t N);
const int SIZE_ARR = 1024;

int main()
{
    int arr3_1[] = { 1, 2, 3, 4, 5, 6, 7 };
    int* res3_1 = findSets(arr3_1, 7);
    int idx = 0;
    while (!(res3_1[idx] == 0 && res3_1[idx + 1] == 0))
    {
        cout << res3_1[idx] << " ";
        idx++;
    }
    cout << "0 0" << endl;
    delete[] res3_1;
}

int* findSets(const int arr[], size_t N)
{
    int totalSubsetsCount = 1;
    for (size_t i = 0; i < N; i++)
    {
        totalSubsetsCount *= 2;
    }

    int* result = new int[SIZE_ARR];
    int resultIndex = 0;
    for (size_t i = 0; i < N; i++)
    {
        int currSize = resultIndex;
        result[resultIndex++] = arr[i];
        result[resultIndex++] = 0;

        int start = 0;
        while (start < currSize)
        {
            int tempCurr = start;
            while (result[tempCurr] != 0)
            {
                result[resultIndex++] = result[tempCurr];
                tempCurr++;
            }
            result[resultIndex++] = arr[i];
            result[resultIndex++] = 0;

            start = tempCurr + 1;
        }
    }
    result[resultIndex++] = 0;
    return result;
}
