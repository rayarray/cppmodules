#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <forward_list>
# include <iterator>
//# include <ranges> // can't implement addNumbers with std::ranges since it's c++20

class Span
{
	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(unsigned int listsize);
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		
		// Methods
		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		//void addNumbers(std::ranges::input_range r);
		//void addNumbers(std::ranges::range r);
		void addNumbers(int array[], unsigned int size);
		template<typename Container>
		void addNumbers(typename Container::const_iterator begin, typename Container::const_iterator end);

		void print();
		
		// Exceptions
		class number_error : public std::exception {
			virtual const char* what() const throw(); };
		class capacity_error : public std::exception {
			virtual const char* what() const throw(); };
		class undefined_error : public std::exception {
			virtual const char* what() const throw(); };
		
	private:
		std::forward_list<int> _list;
		unsigned int _size;
		unsigned int _max;
		int _largestNumber;
		bool _validShortCache;
		unsigned int _shortCache;
};

template<typename Container>
void Span::addNumbers(typename Container::const_iterator begin, typename Container::const_iterator end) {
	(void)(*begin + *end);
	std::forward_list<int> temp_list;
	std::swap<std::forward_list<int> >(temp_list, _list);
	do {
		this->addNumber(*(begin++));
	} while (begin != end);
	std::swap<std::forward_list<int> >(temp_list, _list);
	_list.merge(temp_list);
}

#endif