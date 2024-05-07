#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

#define NOTANUMBER 1
#define MINUS_INFF 2
#define PLUS_INFF 3
#define MINUS_INF 4
#define PLUS_INF 5

#define INVALID_TYPE 0
#define TYPE_CHAR 1
#define TYPE_INT 2
#define TYPE_FLOAT 3
#define TYPE_DOUBLE 4

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