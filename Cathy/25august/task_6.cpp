#include <iostream>
using namespace std;
int AnalyzeNum(long N);
const int SIZE = 32;
void BubbleSort(int* arr, size_t len);

int main()
{
    cout << "314 -> " << AnalyzeNum(314) << " (Expected: 3)" << endl;
    cout << "442 -> " << AnalyzeNum(442) << " (Expected: -1)" << endl;
    cout << "5462141 -> " << AnalyzeNum(5462141) << " (Expected: 4)" << endl << endl;
}

int AnalyzeNum(long N)
{
    if (N < 0)
    {
        N = -N;
    }
    int digits[SIZE];
    int count = 0;
    if (N == 0)
    {
        digits[0] = 0;
        count = 1;
    }
    else
    {
        long temp = N;
        while (temp > 0)
        {
            digits[count++] = temp % 10;
            temp = temp / 10;
        }
    }
    BubbleSort(digits, count);
    if (count % 2 == 0)
    {
        return -1;
    }
    int midIndex = count / 2;
    int smallerCount = midIndex;
    int largerCount = count - 1 - midIndex;
    if (smallerCount == largerCount
        && digits[midIndex] != digits[midIndex - 1]
        && digits[midIndex] != digits[midIndex + 1])
    {
        return digits[midIndex];
    }
    return -1;
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
