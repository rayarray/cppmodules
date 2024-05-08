#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template< typename T>
T	max( T const & one, T const & two) {
	return (( one > two ) ? one : two );
}

template< typename T>
T	min( T const & one, T const & two) {
	return (( one < two ) ? one : two);
}

template< typename T>
void	swap( T & one, T & two) {
	T three = one;
	one = two;
	two = three;
}

#endif