# AlgosLab1

## Скорость выполнения функции
```c++
template <typename F, typename... T>
unsigned get_time(F func, T... args) {
    auto start = std::chrono::steady_clock::now();
    func(args...);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> res = end - start;
    return res.count();
}
```


## Случайные значения
## 1. Случайное число в диапазоне
```cpp
int randint(int min, int max) {
    int res = rand() % max;
    return min + rand() % (max - min + 1);
}
```

## 2. Случайный массим со значениями из диапозона
```cpp
int* randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = randint(min, max);
    return arr;
}
```


## 3. Массив по диапозону
```cpp
int* range(int min, int max) {
    int* arr = new int[max - min + 1];
    for (int i = min; i < max + 1; i++)
        arr[i] = i;
    return arr;
}
```

## 4. Случайный сортированный массив
```cpp
int* sorted_randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    arr[0] = randint(min, max);
    for (int i = 1; i < size; i++)
        arr[i] = randint(arr[i - 1], max);
    return arr;
}
```
