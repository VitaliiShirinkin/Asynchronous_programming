// Задание 3.2 For_each_parallel.cpp

#include <vector>
#include <algorithm>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <future>
#include <random>
#include <iostream>
#include "FuncSort.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russia");

    //создадим вектор случайных чисел
    std::vector<int> randVec = randNum(10, 30);
    std::cout << "Случайный вектор: \n";
    print(randVec);
    auto f_square = [](int& n) {n = n * n; };
    for_each_par(randVec.begin(), randVec.end(), f_square);
    std::cout << std::endl;
    std::cout << "Вектор в квадрате: \n";
    print(randVec);
    return 0;
}

