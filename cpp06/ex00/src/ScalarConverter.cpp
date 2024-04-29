#include "ScalarConverter.hpp"

// Returns int array of 2 values: invalid/char/number/decimals (-1/0/1/2), sign (no 0/+ 1/- 2)
int *checkformat(std::string literal, int *rval)
{
	size_t i = 0, sign = 0, dec = 0;
	rval[0] = rval[1] = -1;
	(void)(i + sign + dec);
	while (i < literal.size() && literal.at(i) == ' ')
		i++;
	if (literal.size() == i && std::isprint(literal.at(i)) && rval[0]++ && ++rval[1])
		return rval;
	//	return ((int[]){0, 0});
	// if (i < literal.size() && ((literal.at(i) == '-' &&sign = 2) || (literal.at(i) == '+' &&sign = 1)))
	// i++;
	while (i < literal.size() && std::isdigit(literal.at(i)))
		i++;
	return rval;
	// if (literal.at(i))
}

size_t leadingSpaces(std::string s)
{
	size_t pos = 0;
	while (pos < s.size() && s.at(pos) == ' ')
		pos++;
	return pos;
}

size_t charCheck(std::string s, size_t pos)
{
	if (s.size() == pos && std::isprint(s.at(pos)))
		return 1;
	return 0;
}

size_t signCheck(std::string s, size_t pos)
{
	if (s.size() < pos)
	{
		if (s.at(pos) == '-')
			return 1;
		else if (s.at(pos) == '+')
			return 2;
	}
	return 0;
}

void ScalarConverter::convert(std::string literal)
{
	(void)literal;
	while (*literal.begin() == ' ')
		literal.pop_back();
	if (*literal.rbegin() == 'f')
		literal.pop_back();
	if (*literal.rbegin() == '-' || *literal.rbegin() == '+')
		std::cout << "Special case! Plus (+) or minus (-) followed by f. Defaulting to zero (0)" << std::endl;
	if (*literal.rbegin() == '.')
		std::cout << "Special case! Last character is a decimal point. Defaulting to ignoring it" << std::endl;
}

void ScalarConverter::cast(std::string literal)
{
	std::cout << "string size " << literal.size() << std::endl;
	std::stringstream ss(literal);
	double d;
	ss >> d;
	std::cout << "Result of double conversion: [" << d << "]" << std::endl;
	int i;
	i = static_cast<int>(d);
	std::cout << "Result of int conversion: [" << i << "]" << std::endl;
	char c;
	c = static_cast<char>(i);
	std::cout << "Result of char conversion: [" << c << "]" << std::endl;
	float f;
	f = static_cast<float>(d);
	std::cout << "Result of float conversion: [" << f << "]" << std::endl;
}