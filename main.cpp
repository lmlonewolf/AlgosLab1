#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <tuple>
#include <windows.h>

// функция замера времени выполнения
template <typename F, typename... T>
unsigned get_time(F func, T... args) {
    auto start = std::chrono::steady_clock::now();
    func(args...);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> res = end - start;
    return res.count();
}


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


// Вывод матрицы
void print_matrix(int** arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << arr[i][j] << '\t';
        std::cout << std::endl;
    }
}





// Поиск элемента в массиве
bool find_in_array(int* arr, unsigned size, int n) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == n)
            flag =  true;
    }
    return flag;
}


// Первфый и второй максимальный элемент массива
std::tuple<int, int> max_in_array(int* arr, unsigned size) {
    int max1 = arr[0];
    int max2 = NULL;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max1)
            max2 = max1, max1 = arr[i];
        else if (arr[i] > max2)
            max2 = arr[i];
    }
    return std::make_tuple(max1, max2);
}


// Бинарный поиск
int binary_search(int* arr, unsigned size, int n) {
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == n)
            return mid;
        if (arr[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


// Таблица умножения
int** math_matrix(unsigned size) {
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
            arr[i][j] = (i + 1) * (j + 1);
    }
    return arr;
}


int main() {
    srand(time(0));

    //  Поиск
    std::cout << std::endl << std::endl << "Search" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << std::endl << "Test " << i + 1 << std::endl;

        unsigned size[] = {1'000u, 10'000u, 100'000u, 1'000'000u, 10'000'000u};
        int* arr = randarray(size[i], 1, 100'000);
        int n = randint(1, 100'000);
        
        std::cout << "Results: " << find_in_array(arr, size[i], n) << std::endl;
        std::cout << "Time: " << get_time(find_in_array, arr, size[i], n) << " microseconds" << std::endl;
        delete[] arr;
    }


    // Максимальные
    std::cout << std::endl << std::endl << "Max" << std::endl;
    for (int i = 0; i < 5; i++) {
        
        std::cout << std::endl << "Test " << i + 1 << std::endl;

        unsigned size[] = { 1'000u, 10'000u, 100'000u, 1'000'000u, 10'000'000u };
        int* arr = randarray(size[i], 1, 100'000);

        auto [max1, max2] = max_in_array(arr, size[i]);

        std::cout << "Results: " << max1 << ' ' << max2 << std::endl;
        std::cout << "Time: " << get_time(max_in_array, arr, size[i]) << " microseconds" << std::endl;
        delete[] arr;
    }


    // Бинарный поиск
    std::cout << std::endl << std::endl << "Binary search" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << std::endl << "Test " << i + 1 << std::endl;

        unsigned size[] = { 1'000u, 10'000u, 100'000u, 1'000'000u, 10'000'000u };
        int* arr = sorted_randarray(size[i] , 1, 1'000'000);
        int n = randint(1, 100'000);

        std::cout << "Results: " << binary_search(arr, size[i], n) << std::endl;
        std::cout << "Time: " << get_time(binary_search, arr, size[i], n) << " microseconds" << std::endl;
        delete[] arr;
    }


    // Матрица
    std::cout << std::endl << std::endl << "Matrix" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << std::endl << "Test " << i + 1 << std::endl;

        unsigned size[] = { 5u, 10u, 100u, 1'000u, 10'000u };
        int** arr = math_matrix(size[i]);
        int n = randint(1, 100'000);

        //std::cout << "Results:" << std::endl;
        //print_matrix(arr, size[i]);
        std::cout << "Time: " << get_time(math_matrix, size[i]) << " microseconds" << std::endl;
        for (int j = 0; j < size[i]; j++)
            delete[] arr[j];
        delete[] arr;
    }
    return 0;
}
