// Да се напише функция на C++, със сигнатура int AnalyzeArray(int arr[], int l), където l е дължината на масива, 
// която да връща 1, ако масивът може да бъде разделен на две части,
// с равни суми на елементите им и 0 – в противен случай. Функцията да връща -1, при невалидни входни данни.

#include <iostream>
using namespace std;
int AnalyzeArray(int arr[], int l);

int main()
{
    int a1[] = { 1, 3, 0, 0, 4 };
    int a2[] = { 1, 6, 1, 0, 5, 199 };
    cout << "{1,3,0,0,4} -> " << AnalyzeArray(a1, 5) << " (Expected: 1)" << endl;
    cout << "{1,6,1,0,5,199} -> " << AnalyzeArray(a2, 6) << " (Expected: 0)" << endl << endl;
}

int AnalyzeArray(int arr[], int l)
{
    if (arr == nullptr || l <= 0)
    {
        return -1;
    }
    int sum = 0;
    for (size_t i = 0; i < l; i++)
    {
        sum = sum + arr[i];
    }
    int leftSum = 0;
    int rightSum = 0;
    for (size_t i = 0; i < l - 1; i++)
    {
        leftSum = leftSum + arr[i];
    }
    rightSum = sum - leftSum;
    if (rightSum == leftSum)
    {
        return 1;
    }
    return 0;
}
