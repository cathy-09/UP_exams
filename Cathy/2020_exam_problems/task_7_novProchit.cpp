#include <iostream>
using namespace std;

int AnalyzeNum(long N);

int main()
{
    cout << "314 -> " << AnalyzeNum(314) << " (Expected: 3)" << endl;
    cout << "442 -> " << AnalyzeNum(442) << " (Expected: -1)" << endl;
    cout << "5462141 -> " << AnalyzeNum(5462141) << " (Expected: 4)" << endl;
    return 0;
}

int AnalyzeNum(long N)
{
    if (N < 0)
    {
        N = -N;
    }

    int digits[32];
    int count = 0;

    if (N == 0)
    {
        digits[count++] = 0;
    }
    else
    {
        long temp = N;
        while (temp > 0)
        {
            digits[count++] = temp % 10;
            temp /= 10;
        }
    }

    // Търсим цифра, която удовлетворява условието
    for (int i = 0; i < count; i++)
    {
        int smallerCount = 0;
        int largerCount = 0;

        for (int j = 0; j < count; j++)
        {
            if (i == j) continue; // Не сравняваме цифрата със себе си

            if (digits[j] < digits[i])
            {
                smallerCount++;
            }
            else if (digits[j] > digits[i])
            {
                largerCount++;
            }
        }

        // Условието: M > 0 (има поне 1 по-малка и 1 по-голяма) и M е еднакъв
        if (smallerCount > 0 && smallerCount == largerCount)
        {
            return digits[i];
        }
    }

    return -1;
}
