#include "Header.h"
#include <algorithm>


char* top_of_stack = nullptr;
size_t peak_memory = 0;

/*
// Замер времени функции
template <typename F, typename... T>
unsigned get_time(F func, T... args) {
    auto start = std::chrono::steady_clock::now();
    func(args...);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> res = end - start;
    return res.count();
}


// Замер памяти функции
template <typename F, typename... T>
size_t func_memory(F func, T... args) {
    char start_marker;
    top_of_stack = &start_marker;
    peak_memory = 0;

    func(args...);

    return peak_memory;
}


// Быстрая сортировка
void quick_sort(int* arr, int l, int r) {
    char current_stack_marker;
    size_t current_usage = std::abs(top_of_stack - &current_stack_marker);
    if (current_usage > peak_memory) peak_memory = current_usage;

    if (l >= r) return;

    int p = arr[l + (r - l) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j) quick_sort(arr, l, j);
    if (i < r) quick_sort(arr, i, r);
}




int main() {
    srand(time(0));

    size_t res = 0;
    int size = 0;
    int* arr = nullptr;


    size = 10;
    arr = randarray(size, 1, 100);
    //print_array(arr, size);
    res = func_memory(quick_sort, arr, 0, size - 1);
    //print_array(arr, size);
    std::cout << "func mem: " << res / 1024 << "KB" << std::endl;
    std::cout << "Time: " << get_time(quick_sort, arr, 0, size - 1) << " microseconds" << std::endl;
    delete[] arr;



    size = 100;
    arr = randarray(size, 1, 1000);
    //print_array(arr, size);
    res = func_memory(quick_sort, arr, 0, size - 1);
    //print_array(arr, size);
    std::cout << "func mem: " << res / 1024 << "KB" << std::endl;
    std::cout << "Time: " << get_time(quick_sort, arr, 0, size - 1) << " microseconds" << std::endl;
    delete[] arr;



    size = 1000;
    arr = randarray(size, 1, 10000);
    //print_array(arr, size);
    res = func_memory(quick_sort, arr, 0, size - 1);
    //print_array(arr, size);
    std::cout << "func mem: " << res / 1024 << "KB" << std::endl;
    std::cout << "Time: " << get_time(quick_sort, arr, 0, size - 1) << " microseconds" << std::endl;
    delete[] arr;



    size = 10000;
    arr = randarray(size, 1, 100000);
    //print_array(arr, size);
    res = func_memory(quick_sort, arr, 0, size - 1);
    //print_array(arr, size);
    std::cout << "func mem: " << res / 1024 << "KB" << std::endl;
    std::cout << "Time: " << get_time(quick_sort, arr, 0, size - 1) << " microseconds" << std::endl;
    delete[] arr;



    size = 100000;
    arr = randarray(size, 1, 1000000);
    //print_array(arr, size);
    res = func_memory(quick_sort, arr, 0, size - 1);
    //print_array(arr, size);
    std::cout << "func size: " << size << std::endl;
    std::cout << "func mem: " << res / 1024 << "KB" << std::endl;
    std::cout << "Time: " << get_time(quick_sort, arr, 0, size - 1) << " microseconds" << std::endl;
    delete[] arr;


    return 0;
}
*/