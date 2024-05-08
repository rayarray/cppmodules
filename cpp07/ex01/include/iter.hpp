#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

template<typename T, typename Fun>
void iter(T* arr, size_t len, Fun fun) {
	for (size_t i = 0; i < len; i++) {
		fun(arr[i]);
	}
}

#include <iostream>

template<typename T = int>
void printElem(T element) {
	std::cout << element << std::endl;
}

template<typename T = int>
void incrementAndPrintElem(T element) {
	element++;
	std::cout << element << std::endl;
}

#endif
