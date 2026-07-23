#include <iostream>
using namespace std;
int** splitArr(int* arr, int M);

int main()
{
    int spArr[] = { 1, 7, 4, 11, 23, 15, 12, 21 };
    int** spRes = splitArr(spArr, 8);
    cout << "{ ";
    for (int i = 0; i < 8; i++)
    {
        cout << "{" << spRes[i][0] << ", " << spRes[i][1] << "}" << (i < 7 ? ", " : " ");
        delete[] spRes[i];
    }
    cout << "}" << endl;
    delete[] spRes;
    cout << endl;
}

int** splitArr(int* arr, int M)
{
    if (arr == nullptr || M <= 0)
    {
        return nullptr;
    }
    int sum = 0;
    for (size_t i = 0; i < M; i++)
    {
        sum = sum + arr[i];
    }
    int average = sum / M;
    int** res = new int* [M];
    for (int i = 0; i < M; i++)
    {
        res[i] = new int[2];
        res[i][0] = arr[i];
        res[i][1] = average;
    }
    return res;
}
