#include <iostream>
using namespace std;
int findIndex(const int arr[], size_t L);

int main()
{
    int arr2_1[] = { 10, 8, 5, 0, 3 };
    cout << findIndex(arr2_1, 5) << endl;             // Очакван изход: 3

    int arr2_2[] = { 0, 1, 0, 2 };
    cout << findIndex(arr2_2, 4) << endl;             // Очакван изход: 1

    int arr2_3[] = { 5, 5, 5, 5, 5 };
    cout << findIndex(arr2_3, 5) << endl;             // Очакван изход: 5

    int arr2_4[] = { 0, 0, 0 };
    cout << findIndex(arr2_4, 3) << endl;             // Очакван изход: 0
}

int findIndex(const int arr[], size_t L)
{
    for (int M = L; M >= 0; M--)
    {
        int count = 0;
        for (size_t i = 0; i < L; i++)
        {
            int N = arr[i];
            if (N >= M)
            {
                count++;
            }
        }
        if (count >= M)
        {
            return M;
        }
    }
    return -1;
}
