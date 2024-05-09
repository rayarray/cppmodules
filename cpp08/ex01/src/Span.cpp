#include "Span.hpp"

// Constructors
Span::Span() : _size(0), _max(0), _validCache(false) {
	_list.resize(0);
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy) : _list(copy._list), _size(copy._size), _max(copy._max), 
	_validCache(copy._validCache), _shortCache(copy._shortCache), _longCache(copy._longCache) {
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int listsize) : _size(0), _max(listsize), _validCache(false) {
	std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
	_list.resize(0);
}

// Destructor
Span::~Span() {
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}

// Operators
Span & Span::operator=(const Span &assign) {
	if (this == &assign)
		return *this;
	_list = assign._list;
	_size = assign._size;
	_max = assign._max;
	_validCache = assign._validCache;
	_shortCache = assign._shortCache;
	_longCache = assign._longCache;
	return *this;
}

void checkListSize(unsigned int _size, bool _empty) {
	if ((_size == 0 && _empty) || _size == 1)
		throw Span::number_error();
	else if (_size == 0 && !_empty) 
		throw Span::undefined_error();
}

unsigned int Span::shortestSpan() {
	checkListSize(_size, _list.empty());
	
}

unsigned int Span::longestSpan() {

}

// Exceptions
const char * Span::number_error::what() const throw() { return "Span: Need two numbers"; }
const char * Span::undefined_error::what() const throw() { return "Span: Something broke :("; }
