#include <iostream>
using namespace std;
int Find(long N, int n);
long naKolkoSheDelim(int n);
int countDigits(long number);

int main()
{
    cout << Find(123456789, 2) << endl;      // 89
    cout << Find(987654321, 3) << endl;      // 987
    cout << Find(120349876, 4) << endl;      // 9876
    cout << Find(1111111, 3) << endl;        // 111
    cout << Find(908172635, 2) << endl;      // 90
    cout << Find(54321, 5) << endl;          // 54321
    cout << Find(100200300, 3) << endl;      // 300
    cout << Find(7654321, 1) << endl;        // 7
    cout << Find(1234567, 6) << endl;        // 234567
    cout << Find(99887766, 4) << endl;       // 9988
}

int Find(long N, int n)
{
    if (N <= 0 || n <= 0 || n >= 8)
    {
        return -1;
    }
    int totalDigits = countDigits(N);
    if (n > totalDigits)
    {
        return -1;
    }
    long delitel = naKolkoSheDelim(n);
    long limits = delitel / 10;
    int maxNumber = -1;
    while (N >= limits)
    {
        int number = N % delitel;
        if (number > maxNumber)
        {
            maxNumber = number;
        }
        N = N / 10;
    }
    return maxNumber;
}

long naKolkoSheDelim(int n)
{
    int delitel = 1;
    for (size_t i = 0; i < n; i++)
    {
        delitel = delitel * 10;
    }
    return delitel;
}

int countDigits(long number)
{
    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }
    return count;
}
