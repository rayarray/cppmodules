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
	if (s.size() == pos + 1 && std::isprint(s.at(pos)))
		return 1;
	return 0;
}

// 0 = not special, 1 = nan, 2 = -inff, 3 = inff, 4 = -inf, 5 = inf
size_t infNanCheck(std::string s, size_t pos)
{
	if (!s.compare(pos, -1, "nan") || !s.compare(pos, -1, "+nan") || !s.compare(pos, -1, "-nan"))
		return 1;
	if (!s.compare(pos, -1, "-inff"))
		return 2;
	if (!s.compare(pos, -1, "+inff") || !s.compare(pos, -1, "inff"))
		return 3;
	if (!s.compare(pos, -1, "-inf"))
		return 4;
	if (!s.compare(pos, -1, "+inf") || !s.compare(pos, -1, "inf"))
		return 5;
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

size_t signCheck2(std::string s)
{
	size_t sign = 0, i = 0;
	while (i < s.size())
	{
		if (s.at(i) == '-')
		{
			if (sign == 0)
				sign = 1;
			else
				return 3;
		}
		else if (s.at(i) == '+')
		{
			if (sign == 0)
				sign = 2;
			else
				return 3;
		}
		i++;
	}
	return sign;
}

size_t digitsCheck(std::string s, size_t pos)
{
	while (pos < s.size() && std::isdigit(s.at(pos)))
		pos++;
	return pos;
}

size_t pointCheck(std::string s, size_t pos)
{
	if (pos < s.size() && s.at(pos) == '.')
		return 1;
	return 0;
}

bool validCheck(std::string s)
{
	size_t pos = leadingSpaces(s);
	int numbers = 0, point = 0, digits = 0, fchar = 0;
	if (charCheck(s, pos))
		return true;
	if (signCheck(s, pos) > 0)
		pos++;
	if (digitsCheck(s, pos) > pos && ++numbers)
		pos = digitsCheck(s, pos);
	if (pointCheck(s, pos) && ++point)
		pos++;
	if (digitsCheck(s, pos) > pos && ++digits)
		pos = digitsCheck(s, pos);
	if (pos < s.size() && s.at(pos) == 'f' && ++pos)
		fchar++;
	return (std::cout << "Invalid input, no representation possible!" << std::endl, pos + 1 == s.size());
}

bool printConversions(int *possible, char c, int i, float f, double d)
{
	(void)(d + f + i + c);
	(void)possible;
	std::cout << "char: ";
	if (possible[0])
		std::cout << c << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (possible[1])
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (possible[2])
		std::cout << f << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (possible[3])
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
	return true;
}

void ScalarConverter::convert(std::string literal)
{
	double d = 0;
	float f = 0;
	int i = 0;
	char c = 0;
	(void)(d + f + i + c);
	size_t pos = leadingSpaces(literal);
	if (infNanCheck(literal, pos) == 1)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
	if (infNanCheck(literal, pos) == 2 || infNanCheck(literal, pos) == 4)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity() * -1, std::numeric_limits<double>::infinity() * -1);
	if (infNanCheck(literal, pos) == 3 || infNanCheck(literal, pos) == 5)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity(), std::numeric_limits<double>::infinity());
	if (!validCheck(literal))
		return;
	if (charCheck(literal, pos))
	{
	}
}

// void ScalarConverter::convert(std::string literal)
// {
// 	(void)literal;
// 	while (*literal.begin() == ' ')
// 		literal.pop_back();
// 	if (*literal.rbegin() == 'f')
// 		literal.pop_back();
// 	if (*literal.rbegin() == '-' || *literal.rbegin() == '+')
// 		std::cout << "Special case! Plus (+) or minus (-) followed by f. Defaulting to zero (0)" << std::endl;
// 	if (*literal.rbegin() == '.')
// 		std::cout << "Special case! Last number is a decimal point. Defaulting to ignoring it" << std::endl;
// }

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
	// c = static_cast<char>(i);
	ss >> c;
	std::cout << "Result of char conversion: [" << c << "]" << std::endl;
	float f;
	f = static_cast<float>(d);
	std::cout << "Result of float conversion: [" << f << "]" << std::endl;
}