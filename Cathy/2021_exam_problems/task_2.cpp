#include <iostream>
using namespace std;
int* convertNum(long num, int k, int m);

int main()
{
    int* cNum1 = convertNum(123456789, 3, 5);
    cout << "(k=3, m=5) 123456789 -> { ";
    for (int i = 0; i < 9; i++) cout << cNum1[i] << (i < 8 ? ", " : " ");
    cout << "} (Expected: 1, 2, 5, 4, 3, 6, 7, 8, 9)" << endl;
    delete[] cNum1;

    int* cNum2 = convertNum(437263, 4, 1);
    cout << "(k=4, m=1) 437263 -> { ";
    for (int i = 0; i < 6; i++) cout << cNum2[i] << (i < 5 ? ", " : " ");
    cout << "} (Expected: 2, 3, 7, 4, 6, 3)" << endl << endl;
}

int* convertNum(long num, int k, int m)
{
    if (num < 0)
    {
        num = -num;
    }
    int len = 0;
    long temp = num;
    if (temp == 0)
    {
        len = 1;
    }
    else
    {
        while (temp > 0) 
        {
            len++;
            temp /= 10;
        }
    }
    temp = num;
    int* tempArray = new int[len];
    for (int i = len - 1; i >= 0; i--)
    {
        tempArray[i] = temp % 10;
        temp = temp / 10;
    }

    if (k - 1 >= 0 && k - 1 < len && m - 1 >= 0 && m - 1 < len)
    {
        int temp = tempArray[k - 1];
        tempArray[k - 1] = tempArray[m - 1];
        tempArray[m - 1] = temp;
    }
    return tempArray;
}
