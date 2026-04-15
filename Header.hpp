#pragma once

#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <windows.h>


// функция замера времени выполнения
template <typename F, typename... T>
unsigned get_time(F func, T... args);


// Случайное число в диапазоне
int randint(int min, int max);


// Случайный массим со значениями из диапозона
int* randarray(unsigned size, int min, int max);


// Диапозон
int* range(int min, int max);


// Случайный сортированный массив
int* sorted_randarray(unsigned size, int min, int max);


// Вывод массива
void print_array(int* arr, unsigned size);


// Вывод матрицы
void print_matrix(int** arr, unsigned size);