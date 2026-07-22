#include <iostream>
using namespace std;
int* countletters(int arr1[], int arr2[], int N);
const int SIZE = 2;

int main()
{
    int c1[] = { 3, 5, 11, 2, 9 };
    int c2[] = { 1, 4, 32, 71, 5 };
    int* countRes = countletters(c1, c2, 5);
    if (countRes)
    {
        cout << "Result: {" << countRes[0] << ", " << countRes[1] << "} (Expected: {1, 0})" << endl;
        delete[] countRes;
    }
    cout << endl;
}

int* countletters(int arr1[], int arr2[], int N)
{
    if (arr1 == nullptr || arr2 == nullptr || N <= 0)
    {
        return nullptr;
    }
    int sum = 0;
    int upperCount = 0;
    int lowerCount = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum = arr1[i] + arr2[i];
        if (sum >= 'A' && sum <= 'Z')
        {
            upperCount++;
        }
        else if (sum >= 'a' && sum <= 'z')
        {
            lowerCount++;
        }
    }
    int* result = new int[SIZE];
    result[0] = upperCount;
    result[1] = lowerCount;

    return result;
}
