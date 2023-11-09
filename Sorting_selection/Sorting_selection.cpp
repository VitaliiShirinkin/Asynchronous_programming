//Задача 3.1 Сортировка выбором
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
    std::vector<int> unsortVec = randNum(100, 30);//для сортировка в одном потоке
    std::vector<int> unsortVec_p = unsortVec;// для сортировка promise
    std::cout << "Неотсортированный вектор: \n";
    print(unsortVec);

    std::vector<int> sortVec;//для сортировка в одном потоке
    std::vector<int> sortVec_p;//для сортировка promise

    //отсиртируем в одном потоке
    while (unsortVec_p.size()>0)
    {
        //создаем promise для передачи результата
        std::promise<std::vector<int>::iterator> promiseObj;

        //получаем future, связанный с promise
        std::future<std::vector<int>::iterator> futureeObj= promiseObj.get_future();

        //запускаем функцию asyncFunc в асинхронном режиме,
        //передавая вектор и promise по ссылке
        std::thread t(findMin, std::ref(unsortVec_p), std::ref(promiseObj));

        //ждем завершения рез-та и получаем рез-т
        std::vector<int>::iterator min = futureeObj.get();
        sortVec_p.push_back(*min);
        unsortVec_p.erase(min);
        t.join();
    }

    std::cout << "Отсортированный вектор (promise thread): \n";
    print(sortVec_p);

    return 0;
}
