#include <iostream>
using namespace std;
char* GetWord(char str[]);
const int SIZE = 32;
int IntToStr(int num, char str[], int startIndex);

int main()
{
    char sentence[] = " It took      about      an hour to                  answer all the questions.               ";
    char* wordRes = GetWord(sentence);
    cout << "Output -> " << wordRes << " (Expected: {4, 10})" << endl;
    delete[] wordRes;
    cout << endl;
}

char* GetWord(char str[])
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int totalWords = 0;
    int aWords = 0;
    bool inWord = false;
    char wordStartChar = '\0';
    int i = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
            {
                totalWords++;
                if (str[i] == 'a' || str[i] == 'A')
                {
                    aWords++;
                }
            }
        }
    }
    char* result = new char[SIZE];
    int index = 0;
    result[index++] = '{';
    index = IntToStr(aWords, result, index);
    result[index++] = ',';
    result[index++] = ' ';
    index = IntToStr(totalWords, result, index);
    result[index++] = '}';
    result[index] = '\0';
    return result;
}

int IntToStr(int num, char str[], int startIndex)
{
    if (num == 0)
    {
        str[startIndex] = '0';
        return startIndex + 1;
    }
    int temp = num;
    int count = 0;
    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }
    int endIdx = startIndex + count;
    for (int i = endIdx - 1; i >= startIndex; i--)
    {
        str[i] = (num % 10) + '0';
        num = num / 10;
    }
    return endIdx;
}
