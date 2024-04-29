#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
private:
	// Constructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);

	// Destructor
	virtual ~ScalarConverter();
	// Operators
	virtual ScalarConverter &operator=(const ScalarConverter &assign);

public:
	static void convert(std::string literal);
	// static int *checkformat(std::string literal, int *rval);
	// static size_t leadingSpaces(std::string s);
	// static size_t charCheck(std::string s, size_t pos);
	// static size_t signCheck(std::string s, size_t pos);
	// static size_t digits(std::string s);
	// static size_t decimals(std::string s);
	static void cast(std::string literal); // remove, only one method allowed
};

#endif