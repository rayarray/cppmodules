#include "Array.hpp"

// Constructors
template<typename T>
Array<T>::Array() {
	std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
	_size = 0;
	_data = nullptr;
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size) {
	try {
	_data = new T[size]();
	} catch (std::bad_alloc&) {
		throw cannot_alloc();
	}
}

template<typename T>
Array<T>::Array(const Array &copy) : Array(copy._size) {
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
	for (unsigned int i = 0; i < _size; i++) {
		this[i] = copy[i];
	}
}

// Destructor
template<typename T>
Array<T>::~Array() {
	std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
	delete _data;
}


// Operators
template<typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign) {
	if (this == assign) return *this;
	delete (this);
	(this) = new Array<T>(assign._size);
	for (unsigned int i = 0; i < _size; i++) {
		this[i] = assign[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index + 1 > _size)
		throw out_of_bound();
	return *(_data + (sizeof(T) * index));
}

// Exceptions
template<typename T>
const char *Array<T>::out_of_bound::what() const throw() { return "Array: index out of bounds!"; }

template<typename T>
const char *Array<T>::cannot_alloc::what() const throw() { return "Array: memory allocation failed!"; }
