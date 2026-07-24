#include <iostream>
using namespace std;
int* mergeArrays(int arr1[], int arr2[], int m);

int main()
{
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5, 6 };
    int m = 3;
    // Очаквано: a[0]+b[2]=1+6=7, a[1]+b[1]=2+5=7, a[2]+b[0]=3+4=7
    int* merged = mergeArrays(a, b, m);
    for (int i = 0; i < m; i++)
    {
        cout << merged[i] << " ";
    }
    cout << "(7 7 7)" << endl;
    delete[] merged;
    cout << endl;
}

int* mergeArrays(int arr1[], int arr2[], int m)
{
    int* temp = new int[m];
    for (size_t i = 0; i < m; i++)
    {
        temp[i] = arr1[i] + arr2[m - i - 1];
    }
    return temp;
}
