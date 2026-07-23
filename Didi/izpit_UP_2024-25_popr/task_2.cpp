//OSHTE TAKIVA ZADACHI DAJ BOJE

#include <iostream>

int* mergeArrays(int first[], int second[], int m) {
    int* merged = new int[m];
    int index = 0;

    for (size_t i = 0; i < m; i++)
    {
        merged[index++] = first[i] + second[m - i - 1];
    }

    return merged;
}

int main()
{
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5, 6 };
    int m = 3;
    // Expected: a[0]+b[2]=1+6=7, a[1]+b[1]=2+5=7, a[2]+b[0]=3+4=7
    int* merged = mergeArrays(a, b, m);
    for (int i = 0; i < m; i++)
    {
        std::cout << merged[i] << " ";
    }
    std::cout << "Expected:" << "(7 7 7)" << std::endl;
    delete[] merged;
}
