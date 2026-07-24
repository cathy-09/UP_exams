#include <iostream>
using namespace std;
bool findWord(const char* const* grid, size_t M, size_t N, const char* word);

int main()
{
    size_t M = 3;
    size_t N = 4;
    char** myGrid = new char* [M];
    for (size_t i = 0; i < M; i++)
    {
        myGrid[i] = new char[N];
    }
    // C  A  T  X
    // X  X  S  E
    // X  X  X  R
    myGrid[0][0] = 'C'; 
    myGrid[0][1] = 'A';
    myGrid[0][2] = 'T'; 
    myGrid[0][3] = 'X';
    myGrid[1][0] = 'X'; 
    myGrid[1][1] = 'X';
    myGrid[1][2] = 'S';
    myGrid[1][3] = 'E';
    myGrid[2][0] = 'X';
    myGrid[2][1] = 'X'; 
    myGrid[2][2] = 'X'; 
    myGrid[2][3] = 'R';

    bool test1 = findWord(myGrid, M, N, "CAT");
    cout << "CAT: " << (test1 ? "true" : "false") << endl; // Очакван изход: true

    bool test2 = findWord(myGrid, M, N, "CATSE");
    cout << "CATSE: " << (test2 ? "true" : "false") << endl; // Очакван изход: true

    bool test3 = findWord(myGrid, M, N, "TE");
    cout << "TE: " << (test3 ? "true" : "false") << endl; // Очакван изход: false
}

bool findWord(const char* const* grid, size_t M, size_t N, const char* word)
{
    if (word[0] == '\0')
    {
        return true;
    }
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (grid[i][j] == word[0])
            {
                size_t currRow = i;
                size_t currCol = j;
                size_t nextCell = 1;
                while (word[nextCell] != '\0')
                {
                    bool found = false;
                    if (currCol + 1 < N && grid[currRow][currCol + 1] == word[nextCell])
                    {
                        currCol = currCol + 1;
                        found = true;
                    }
                    else if (currRow + 1 < M && grid[currRow + 1][currCol] == word[nextCell])
                    {
                        currRow = currRow + 1;
                        found = true;
                    }
                    else if (currCol > 0 && grid[currRow][currCol - 1] == word[nextCell])
                    {
                        currCol = currCol - 1;
                        found = true;
                    }
                    else if (currRow > 0 && grid[currRow - 1][currCol] == word[nextCell])
                    {
                        currRow = currRow - 1;
                        found = true;
                    }

                    if (found == false)
                    {
                        break;
                    }

                    nextCell++;
                }

                if (word[nextCell] == '\0')
                {
                    return true;
                }
            }
        }
    }

    return false;
}
