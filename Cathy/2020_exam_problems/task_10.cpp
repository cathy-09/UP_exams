#include <iostream>
using namespace std;
int** mergearrays(int* array1, int* array2, int m);
const int SIZE = 2;

int main()
{
    int m1[] = { 3, 5, 11, 2, 9 };
    int m2[] = { 1, 4, 32, 71, 5 };
    int** merged = mergearrays(m1, m2, 5);
    if (merged)
    {
        cout << "Merged array:" << endl << "{ ";
        for (int r = 0; r < 2; r++)
        {
            cout << "{ ";
            for (int c = 0; c < 5; c++)
            {
                cout << merged[r][c] << (c < 4 ? ", " : " ");
            }
            cout << "}" << (r == 0 ? ", " : " ");
        }
        cout << "}" << endl;

        delete[] merged[0];
        delete[] merged[1];
        delete[] merged;
    }

    return 0;
}

int** mergearrays(int* array1, int* array2, int m)
{
    if (array1 == nullptr || array2 == nullptr || m <= 0)
    {
        return nullptr;
    }
    int** result = new int*[SIZE];
    result[0] = new int[m];
    result[1] = new int[m];
    for (size_t i = 0; i < m; i++)
    {
        result[0][i] = array1[i]; 
        result[1][i] = array2[i];
    }
    return result;
}
