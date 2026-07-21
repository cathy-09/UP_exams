#include <iostream>
using namespace std;
int Check(const unsigned int* arr, int N);
const int SIZE = 32;

int main()
{
    // Елементи: 1, 5, 2, 6 -> Разлики: |1-5|=4, |5-2|=3, |2-6|=4 -> Редицата от разлики е [4, 3, 4] (огледална!)
    unsigned int arr1[] = { 1, 5, 2, 6 };
    cout << "{1, 5, 2, 6} -> " << Check(arr1, 4) << " (: 1)" << endl;

    // Елементи: 1, 10, 2, 3 -> Разлики: |1-10|=9, |10-2|=8, |2-3|=1 -> Редицата е [9, 8, 1] (не е огледална)
    unsigned int arr2[] = { 1, 10, 2, 3 };
    cout << "{1, 10, 2, 3} -> " << Check(arr2, 4) << " (: 0)" << endl;
    cout << endl;
}

int Check(const unsigned int* arr, int N)
{
    if (N < 3)
    {
        return false;
    }
    int razliki[SIZE];
    int razlikiCount = N - 1;
    for (size_t i = 0; i < razlikiCount; i++)
    {
        int razlikiInt = arr[i] - arr[i + 1];
        if (razlikiInt < 0)
        {
            razlikiInt = -razlikiInt;
        }
        razliki[i] = razlikiInt;
    }
    for (size_t i = 0; i < razlikiCount / 2; i++)
    {
        if (razliki[i] != razliki[razlikiCount - i - 1])
        {
            return false;
        }
    }
    return true;
}
