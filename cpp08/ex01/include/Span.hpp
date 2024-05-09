#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <forward_list>

# define LOOP_AROUND 1

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
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		// Exceptions
		class number_error : public std::exception {
			virtual const char* what() const throw(); };
		class undefined_error : public std::exception {
			virtual const char* what() const throw(); };
		
	private:
		std::forward_list<int>	_list;
		unsigned int			_size;
		unsigned int			_max;
		bool					_validCache;
		unsigned int			_shortCache;
		unsigned int			_longCache;
};

#endif