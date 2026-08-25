#include <iostream>
char* CheckStr(char str[]);
int myCount(char str[]);
int const SIZE = 256;

int main()
{
    // Тест 1: Пример от условието с няколко повторения
    char test1[] = "aif8sltt8f";
    char* res1 = CheckStr(test1);
    std::cout << "Test 1 (\"aif8sltt8f\"): Expected \"f8t\", Got: \""
        << (res1 ? res1 : "nullptr") << "\"" << std::endl;
    delete[] res1; // Освобождаване на заделената памет

    // Тест 2: Пример от условието без повтарящи се символи
    char test2[] = "asdfgjk";
    char* res2 = CheckStr(test2);
    std::cout << "Test 2 (\"asdfgjk\"): Expected \"\", Got: \""
        << (res2 ? res2 : "nullptr") << "\"" << std::endl;
    delete[] res2;

    // Тест 3: Всички символи се повтарят
    char test3[] = "aabbcc";
    char* res3 = CheckStr(test3);
    std::cout << "Test 3 (\"aabbcc\"): Expected \"abc\", Got: \""
        << (res3 ? res3 : "nullptr") << "\"" << std::endl;
    delete[] res3;

    // Тест 4: Празен низ
    char test4[] = "";
    char* res4 = CheckStr(test4);
    std::cout << "Test 4 (\"\"): Expected \"\", Got: \""
        << (res4 ? res4 : "nullptr") << "\"" << std::endl;
    delete[] res4;

    // Тест 5: Невалиден вход (nullptr)
    char* res5 = CheckStr(nullptr);
    std::cout << "Test 5 (NULL): Expected nullptr, Got: "
        << (res5 ? res5 : "nullptr") << std::endl;
    delete[] res5;

    return 0;
}

char* CheckStr(char str[])
{
    if (str == nullptr)
    {
        return nullptr;
    }
    int count = myCount(str);
    char* result = new char[SIZE];
    int index = 0;
    int countCh[SIZE] = { 0 };
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char charche = str[i];
        countCh[charche]++;
    }
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char charche = str[i];
        if (countCh[charche] > 1)
        {
            result[index] = charche;
            index++;
            countCh[charche] = 0;
        }
    }
    result[index] = '\0';
    return result;
}

int myCount(char str[])
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
