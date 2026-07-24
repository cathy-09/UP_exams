#include <iostream>
using namespace std;
void squareArr(int* arr, size_t len);
void BubbleSort(int* arr, size_t len);

int main()
{
    int arr1[] = { -4, -1, 0, 3, 10 };
    size_t len1 = 5;
    squareArr(arr1, len1);

    cout << "[-4, -1, 0, 3, 10] -> Power of two: ";
    for (size_t i = 0; i < len1; i++) cout << arr1[i] << " ";
    cout << "(Expected: 0 1 9 16 100)" << endl;

    int arr2[] = { -7, -3, -1 };
    size_t len2 = 3;
    squareArr(arr2, len2);

    cout << "[-7, -3, -1] -> Power of two:: ";
    for (size_t i = 0; i < len2; i++) cout << arr2[i] << " ";
    cout << "(Expected: 1 9 49)" << endl << endl;
}

void squareArr(int* arr, size_t len)
{
    if (arr == nullptr || len == 0)
    {
        return;
    }
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = arr[i] * arr[i];
    }

    BubbleSort(arr, len);
}

void BubbleSort(int* arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
