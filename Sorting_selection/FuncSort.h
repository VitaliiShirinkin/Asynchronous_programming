#pragma once

#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <future>

//функция генерации вектора размерность N случ чисел
//равномерного распределения в диапазоне от 0 до range
std::vector<int> randNum(int range, int N) {
	std::vector<int> res;
	for (int It = 0; It < N; It++) {

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, range);
		res.push_back(dist(gen));
	}
	return res;
}

//Функция вывода вектора на экран
template <class T>
void print(const std::vector<T>& vec) {
	auto it = vec.begin();
	while (it !=vec.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
}

void findMin(std::vector<int>& data, std::promise<std::vector<int>::iterator>& promiseObj) {
	std::vector<int>::iterator min = std::min_element(data.begin(), data.end());
	promiseObj.set_value(min);
}


