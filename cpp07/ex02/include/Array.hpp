#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

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
		T		&operator[](size_t index);
		const T	&operator[](size_t index) const;
		T		&getidx(size_t index);

		// Exceptions
		class out_of_bound : public std::exception {
			virtual const char* what() const throw();
		};
		class cannot_alloc : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		size_t	_size;
		T		*_data;
};

# include "Array.tpp"

#endif