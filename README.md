# Лабораторная работа 1

--- 
# Скорость выполнения функции
```cpp
template <typename F, typename... T>
unsigned get_time(F func, T... args) {
    auto start = std::chrono::steady_clock::now();
    func(args...);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> res = end - start;
    return res.count();
}
```

---

# Случайные значения
- ## Случайное число в диапазоне
```cpp
int randint(int min, int max) {
    int res = rand() % max;
    return min + rand() % (max - min + 1);
}
```

- ## Случайный массим со значениями из диапозона
```cpp
int* randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = randint(min, max);
    return arr;
}
```


- ## Массив по диапозону
```cpp
int* range(int min, int max) {
    int* arr = new int[max - min + 1];
    for (int i = min; i < max + 1; i++)
        arr[i] = i;
    return arr;
}
```

- ## Случайный сортированный массив
```cpp
int* sorted_randarray(unsigned size, int min, int max) {
    int* arr = new int[size];
    arr[0] = randint(min, max);
    for (int i = 1; i < size; i++)
        arr[i] = randint(arr[i - 1], max);
    return arr;
}
```

---

# Задачи

## 1.  Проверка наличия элемента в массиве
```cpp
bool find_in_array(int* arr, unsigned size, int n) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == n)
            flag =  true;
    }
    return flag;
}
```
### Тесты
<table>
    <tr>
        <th>Номер теста</th>
        <th>Размер массива</th>
        <th>Время выполнения</th>
    </tr>
    <tr>
        <td>1</td>
        <td>1.000</td>
        <td>0,000002 сек</td>
    </tr>
    <tr>
        <td>2</td>
        <td>10.000</td>
        <td>0,000022 сек</td>
    </tr>
    <tr>
        <td>3</td>
        <td>100.000</td>
        <td>0,000220 сек</td>
    </tr>
    <tr>
        <td>4</td>
        <td>1.000.000</td>
        <td>0,002300 сек</td>
    </tr>
    <tr>
        <td>5</td>
        <td>10.000.000</td>
        <td>0,023322 сек</td>
    </tr>
</table>

---

## 2. Поиск второго максимального элемента
```cpp
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
```
### Тесты
<table>
    <tr>
    <tr>
        <th>Номер теста</th>
        <th>Размер массива</th>
        <th>Время выполнения</th>
    </tr>
    <tr>
        <td>1</td>
        <td>1.000</td>
        <td>0,000003 сек</td>
    </tr>
    <tr>
        <td>2</td>
        <td>10.000</td>
        <td>0,000025 сек</td>
    </tr>
    <tr>
        <td>3</td>
        <td>100.000</td>
        <td>0,000263 сек</td>
    </tr>
    <tr>
        <td>4</td>
        <td>1.000.000</td>
        <td>0,002528 сек</td>
    </tr>
    <tr>
        <td>5</td>
        <td>10.000.000</td>
        <td>0,025180 сек</td>
    </tr>
</table>

---

## 3. Бинарный поиск
```cpp
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
```
### Тесты
<table>
    <tr>
        <th>Номер теста</th>
        <th>Размер массива</th>
        <th>Время выполнения</th>
    </tr>
    <tr>
        <td>1</td>
        <td>1.000</td>
        <td>0,000000 сек</td>
    </tr>
    <tr>
        <td>2</td>
        <td>10.000</td>
        <td>0,000000 сек</td>
    </tr>
    <tr>
        <td>3</td>
        <td>100.000</td>
        <td>0,000000 сек</td>
    </tr>
    <tr>
        <td>4</td>
        <td>1.000.000</td>
        <td>0,000000 сек</td>
    </tr>
    <tr>
        <td>5</td>
        <td>10.000.000</td>
        <td>0,000001 сек</td>
    </tr>
</table>

---

## 4. Построение таблицы умножения
```cpp
int** math_matrix(unsigned size) {
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
            arr[i][j] = (i + 1) * (j + 1);
    }
    return arr;
}
```

### Тесты
<table>
    <tr>
        <th>Номер теста</th>
        <th>Размер массива</th>
        <th>Время выполнения</th>
    </tr>
    <tr>
        <td>1</td>
        <td>5</td>
        <td>0,000001 сек</td>
    </tr>
    <tr>
        <td>2</td>
        <td>10</td>
        <td>0,000006 сек</td>
    </tr>
    <tr>
        <td>3</td>
        <td>100</td>
        <td>0,000068 сек</td>
    </tr>
    <tr>
        <td>4</td>
        <td>1.000</td>
        <td>0,005061 сек</td>
    </tr>
    <tr>
        <td>5</td>
        <td>10.000</td>
        <td>0,503860 сек</td>
    </tr>
</table>

