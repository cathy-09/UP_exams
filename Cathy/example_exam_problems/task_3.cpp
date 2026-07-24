#include <iostream>
using namespace std;
void printCenteredRectangle(int n, int m, char charche);

int main()
{
    printCenteredRectangle(3, 10, '*');
    cout << endl;
}

void printCenteredRectangle(int n, int m, char charche)
{
    int startRow = (25 - n) / 2;
    int startCol = (80 - m) / 2;
    if (startRow < 0)
    {
        startRow = 0;
    }
    if (startCol < 0)
    {
        startCol = 0;
    }
    for (size_t i = 0; i < startRow; i++)
    {
        cout << '\n';
    }
    for (size_t r = 0; r < n; r++)
    {
        for (size_t c = 0; c < startCol; c++)
        {
            cout << ' ';
        }
        for (size_t k = 0; k < m; k++)
        {
            cout << charche;
        }
        cout << '\n';
    }
}
