#include <iostream>
using namespace std;
int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal);

int main()
{
    int arr1[] = { 1, 2, 6, 7 }; // Сума = 16, Ср. аритм = 4. Най-близко е 2 или 6 (и двете са на разстояние 2).
    int min1 = 0, max1 = 0;
    int closest1 = findMaxMin(arr1, 4, min1, max1);
    cout << "{1, 2, 6, 7} -> min: " << min1 << ", max: " << max1 << ", close to average: " << closest1 << endl;

    int arr2[] = { 10, 20, 30 }; // Сума = 60, Ср. аритм = 20. Най-близко е 20.
    int min2 = 0, max2 = 0;
    int closest2 = findMaxMin(arr2, 3, min2, max2);
    cout << "{10, 20, 30} -> min: " << min2 << ", max: " << max2 << ", close to average: " << closest2 << endl;
    cout << endl;
}

int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal)
{
    minVal = 123456789;
    maxVal = -123456789;
    double sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
        sum = sum + arr[i];
    }
    double average = sum / size;

    int naiBlizko = arr[0];
    double min = average - arr[0];
    if (min < 0)
    {
        min = -min;
    }
    for (size_t i = 1; i < size; i++)
    {
        double currMin = average - arr[i];
        if (currMin < 0)
        {
            currMin = -currMin;
        }
        if (currMin < min)
        {
            min = currMin;
            naiBlizko = arr[i];
        }
    }
    return naiBlizko;
}
