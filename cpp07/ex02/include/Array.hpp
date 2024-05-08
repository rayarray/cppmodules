#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

struct bigData {
	long double hog[16384];
};

template<typename T = int>
class Array
{
	public:
		// Constructors
		Array();
		Array(unsigned int size);
		Array(Array const &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array 	&operator=(const Array &assign);
		T		&operator[](unsigned int index);
		T		&getidx(unsigned int index);

		// Exceptions
		class out_of_bound : public std::exception {
			virtual const char* what() const throw();
		};
		class cannot_alloc : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		unsigned int	_size;
		T				*_data;
};

# include "Array.tpp"

#endif