#include "Header.h"


// Случайное число в диапазоне
int randint(int min, int max) {
    int res = rand() % max;
    return min + rand() % (max - min + 1);
}

// Случайный массим со значениями из диапозона
int* randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = randint(min, max);
    return arr;
}

// Диапозон
int* range(int min, int max) {
    int* arr = new int[max - min + 1];
    for (int i = min; i < max + 1; i++)
        arr[i] = i;
    return arr;
}

// Случайный сортированный массив
int* sorted_randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    arr[0] = randint(min, max);
    for (int i = 1; i < size; i++)
        arr[i] = randint(arr[i - 1], max);
    return arr;
}


// Вывод массива
void print_array(int* arr, unsigned size) {
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


// Вывод матрицы
void print_matrix(int** arr, unsigned size) {
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << arr[i][j] << '\t';
        std::cout << std::endl;
    }
}