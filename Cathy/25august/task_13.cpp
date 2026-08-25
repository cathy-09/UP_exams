int main()
{
    char strW[] = "this is a teSt string";
    char* gw1 = getWord(strW, 4);
    cout << "(k=4) -> \"" << gw1 << "\" (Expected: TEsT)" << endl;
    delete[] gw1;

    char* gw2 = getWord(strW, 1);
    cout << "(k=1) -> \"" << gw2 << "\" (Expected: THIS)" << endl;
    delete[] gw2;

    char* gw3 = getWord(strW, 10);
    cout << "(k=10) -> \"" << gw3 << "\" (Expected: Wrong number!)" << endl;
    delete[] gw3;
    cout << endl;
}

char* getWord(char* str, int k)
{
    if (str == nullptr || k <= 0)
    {
        return MakeErrorMsg();
    }
    int wordCout = 0;
    int start = -1;
    int lenWord = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char charche = str[i];
        if (!(charche == ' ' || charche == '\t' || str[i + 1] == '\0'))
        {
            if (start == -1)
            {
                start = i;
                lenWord = 0;
            }
            lenWord++;
        }
        else
        {
            if (start != -1)
            {
                wordCout++;
                if (wordCout == k)
                {
                    char* result = new char[lenWord + 1];
                    for (size_t j = 0; j < lenWord; j++)
                    {
                        char charcheWord = str[start + j];
                        if (charcheWord >= 'a' && charcheWord <= 'z')
                        {
                            charcheWord = charcheWord - 'a' + 'A';
                        }
                        else if (charcheWord >= 'A' && charcheWord <= 'Z')
                        {
                            charcheWord = charcheWord - 'A' + 'a';
                        }
                        result[j] = charcheWord;
                    }
                    result[lenWord] = '\0';
                    return result;
                }
                start = -1;
            }
        }
    }
    return MakeErrorMsg();
}

char* MakeErrorMsg()
{
    char msg[] = "Wrong number!";
    char* result = new char[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = msg[i];
    }
    return result;
}
