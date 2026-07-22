#include <iostream>
using namespace std;
int findElement(long arr[], int l);

int main()
{
    long elemArr[] = { 2, 3, 17, 8, 1, 9 };
    cout << "Right index -> " << findElement(elemArr, 6) << " (Expected: 2)" << endl << endl;
}

int findElement(long arr[], int l) 
{
    if (arr == nullptr || l < 3)
    {
        return -1;
    }
    double average = 0.0;
    for (int i = l - 2; i >= 1; i--)
    {
        average = (arr[i - 1] + arr[i + 1]) / 2.0;
        if (arr[i] > average)
        {
            return i;
        }
    }
    return -1;
}
