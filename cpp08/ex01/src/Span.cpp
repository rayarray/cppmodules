#include "Span.hpp"

// Constructors
Span::Span() : _size(0), _max(0), _largestNumber(std::numeric_limits<int>::min()) {
	_list.resize(0);
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
	_validShortCache = false;
	
}

Span::Span(const Span &copy) : _list(copy._list), _size(copy._size), _max(copy._max), 
			_largestNumber(copy._largestNumber), _shortCache(copy._shortCache)  {
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
	_validShortCache = false;
}

Span::Span(unsigned int listsize) : _size(0), _max(listsize), _largestNumber(std::numeric_limits<int>::min()), 
		_validShortCache(false) {
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
	_validShortCache = assign._validShortCache;
	_shortCache = assign._shortCache;
	_largestNumber = assign._largestNumber;
	return *this;
}

void Span::addNumber(int number) {
	if (_size == _max)
		throw Span::capacity_error();
	std::forward_list<int>::iterator iter = _list.before_begin();
	bool inserted = false;
	for (std::forward_list<int>::iterator i = _list.begin(); !inserted && i != _list.end(); i++) {
		if (number < *i) {
			_list.insert_after(iter, number);
			inserted = true;
		}
		iter = i;
	}
	if (!inserted)
		_list.insert_after(iter, number);
	_size++;
	_validShortCache = false;
	_largestNumber = (_largestNumber < number ) ? number : _largestNumber;
}

void checkListSize(const unsigned int _size, const bool _empty) {
	if ((_size == 0 && _empty) || _size == 1)
		throw Span::number_error();
	else if (_size == 0 && !_empty) 
		throw Span::undefined_error();
}

// breaks if small > large!
inline unsigned int getSpan(const int small, const int large) { return static_cast<unsigned int>(large - small); }

unsigned int Span::shortestSpan() {
	checkListSize(_size, _list.empty());
	if (_validShortCache) return _shortCache;
	_shortCache = -1;
	for (std::forward_list<int>::const_iterator i = _list.cbegin(); std::next(i) != _list.cend(); i++) {
		_shortCache = (_shortCache > getSpan(*i, *(std::next(i)))) ? *(std::next(i)) - *i : _shortCache;
	}
	return (_validShortCache = true, _shortCache);
}

void Span::addNumbers(int array[], unsigned int size) {
	if (size > _max - _size)
		throw Span::capacity_error();
	if (size == 0) return;
	std::forward_list<int> temp_list;
	std::swap<std::forward_list<int> >(temp_list, _list);
	//_list.resize(0);
	for (unsigned int i = 0; i < size; i++)
		this->addNumber(array[i]);
	std::swap<std::forward_list<int> >(temp_list, _list);
	_list.merge(temp_list);
}

unsigned int Span::longestSpan() {
	checkListSize(_size, _list.empty());
	return (getSpan(_list.front(), _largestNumber));
}

void Span::print() {
	std::cout << "Span::print: { ";
	for (std::forward_list<int>::const_iterator i = _list.cbegin(); i != _list.cend(); i++ )
		std::cout << *i << " ";
	std::cout << "}" << std::endl;
}

// Exceptions
const char * Span::number_error::what() const throw() { return "Span: Need two numbers"; }
const char * Span::capacity_error::what() const throw() { return "Span: Capacity reached"; }
const char * Span::undefined_error::what() const throw() { return "Span: Something broke :("; }
