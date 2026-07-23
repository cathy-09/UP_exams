//DJEMINI SHTE SI POLZVAM MEHURCHETO!!!

#include <iostream>

void mySwap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void myBubbleSort(int* array, size_t len) {

    if (array == nullptr || len < 2) {
        return;
    }

    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1]) {
                mySwap(array[j], array[j + 1]);
            }
        }
    }
}

void squareArr(int* array, size_t len) {

    for (size_t i = 0; i < len; i++)
    {
        array[i] *= array[i];
    }

    myBubbleSort(array, len);
}

int main() {
    {
        int arr[] = { -4, -1, 0, 3, 10 };
        size_t len = 5;
        std::cout << "{-4, -1, 0, 3, 10} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({0, 1, 9, 16, 100})" << std::endl;
    }

    {
        int arr[] = { -5, -4, -3, -2, -1 };
        size_t len = 5;
        std::cout << "{-5, -4, -3, -2, -1} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({1, 4, 9, 16, 25})" << std::endl;
    }

    {
        int arr[] = { 1, 2, 3, 4, 5 };
        size_t len = 5;
        std::cout << "{1, 2, 3, 4, 5} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({1, 4, 9, 16, 25})" << std::endl;
    }

    {
        int arr[] = { -7, -3, 2, 4 };
        size_t len = 4;
        std::cout << "{-7, -3, 2, 4} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({4, 9, 16, 49})" << std::endl;
    }

    {
        int arr[] = { -3, -1, 1, 3 };
        size_t len = 4;
        std::cout << "{-3, -1, 1, 3} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({1, 1, 9, 9})" << std::endl;
    }

    {
        int arr[] = { -5 };
        size_t len = 1;
        std::cout << "{-5} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({25})" << std::endl;
    }

    {
        int arr[] = { 0 };
        size_t len = 1;
        std::cout << "{0} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({0})" << std::endl;
    }

    {
        int* arr = nullptr;
        size_t len = 0;
        std::cout << "{} -> {";
        squareArr(arr, len);
        for (size_t i = 0; i < len; ++i) {
            std::cout << arr[i] << (i + 1 < len ? ", " : "");
        }
        std::cout << "} ({})" << std::endl;
    }

    return 0;
}

