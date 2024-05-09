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
	std::cout << "\e[0;33mNormal Constructor called of Array\e[0m" << std::endl;
	try {
	_data = new T[size]();
	} catch (std::bad_alloc&) {
		throw cannot_alloc();
}	}

template<typename T>
Array<T>::Array(const Array<T> &copy) : Array<T>(copy._size) {
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
	std::memcpy(_data, copy._data, static_cast<size_t>(_size) * sizeof(T));
}

// Destructor
template<typename T>
Array<T>::~Array() {
	std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
	delete[] _data;
}

// Operators
template<typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign) {
	if (this == &assign) return *this;
	delete[] _data;
	_size = assign._size;
	try {
	_data = new T[_size]();
	} catch (std::bad_alloc&) {
		throw cannot_alloc();
	}
	for (unsigned int i = 0; i < _size; i++) {
		this->_data[i] = assign[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw out_of_bound();
	return this->_data[index];
}

template<typename T>
const T &Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw out_of_bound();
	return this->_data[index];
}

// Exceptions
template<typename T>
const char *Array<T>::out_of_bound::what() const throw() { return "Array: index out of bounds!"; }

template<typename T>
const char *Array<T>::cannot_alloc::what() const throw() { return "Array: memory allocation failed!"; }
