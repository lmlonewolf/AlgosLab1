#include "Header.hpp"
#include <algorithm>


// Деление на части
int partition(int* arr, int l, int r) {
    int temp = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < temp) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}


// Быстрая сортировка
void quick_sort(int* arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quick_sort(arr, l, pi - 1);
        quick_sort(arr, pi + 1, r);
    }
}


int main() {
    srand(time(0));

    unsigned size = 10;
    int* arr = randarray(size, 1, 100);
    print_array(arr, size);

    quick_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}