#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

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
};

#endif