#include "ScalarConverter.hpp"

size_t leadingSpaces(std::string s) {
	size_t pos = 0;
	while (pos < s.size() && s.at(pos) == ' ')
		if (pos + 1 == s.size() && s.at(pos) == ' ')
			return pos;
		pos++;
	return pos;
}

size_t charCheck(std::string s, size_t pos) {
	//if (s.size() == pos + 3 && s.at(pos) == '\'' && std::isprint(s.at(pos + 1)) && s.at(pos + 2) == '\'')
	//	return 1;
	//return 0;
	return (s.size() == pos + 3 && s.at(pos) == '\'' && s.at(pos + 2) == '\'');
}

// 0 = not special, 1 = nan, 2 = -inff, 3 = inff, 4 = -inf, 5 = inf
size_t infNanCheck(std::string s, size_t pos) {
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

size_t signCheck(std::string s, size_t pos) {
	if (s.size() > pos) {
		if (s.at(pos) == '-')
			return 1;
		else if (s.at(pos) == '+')
			return 2;
	}
	return 0;
}

// size_t signCheck2(std::string s) {
// 	size_t sign = 0, i = 0;
// 	while (i < s.size()) {
// 		if (s.at(i) == '-') {
// 			if (sign == 0)
// 				sign = 1;
// 			else
// 				return 3;
// 		}
// 		else if (s.at(i) == '+') {
// 			if (sign == 0)
// 				sign = 2;
// 			else
// 				return 3;
// 		}
// 		i++;
// 	}
// 	return sign;
// }

size_t digitsCheck(std::string s, size_t pos) {
	while (pos < s.size() && std::isdigit(s.at(pos)))
		pos++;
	return pos; 
}

std::string getDigits(std::string s, size_t pos) { return (s.substr(pos, digitsCheck(s, pos))); }

size_t pointCheck(std::string s, size_t pos) {
	if (pos < s.size() && s.at(pos) == '.')
		return 1;
	return 0;
}

// returns 0 if not valid, 1 for char, 2 for int, 3 for float, 4 for double
int validCheck(std::string s) {
	size_t pos = leadingSpaces(s);
	int numbers = 0, point = 0, digits = 0, fchar = 0;
	if (charCheck(s, pos))
		return 1;
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
	if (numbers && !point && !digits && !fchar)
		return 2;
	if ((numbers || (point && (digits || numbers))) && fchar)
		return 3;
	if (point && (numbers || digits) && !fchar)
		return 4;
	return (std::cout << "Invalid input, no representation possible!" << std::endl, pos + 1 == s.size());
}

bool printConversions(int *possible, char c, int i, float f, double d, std::string strs)
{
	std::cout << "char: ";
	if (possible[0])
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (possible[1])
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (possible[2]) {
		std::cout << f << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (possible[3])
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
	return true;
}

void printInfNan(int special_type)
{
	if (special_type == NOTANUMBER)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
	else if (special_type == MINUS_INFF || special_type == MINUS_INF)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity() * -1, std::numeric_limits<double>::infinity() * -1);
	else if (special_type == PLUS_INFF || special_type == PLUS_INF)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity(), std::numeric_limits<double>::infinity());
}

void printChar(std::string s, size_t pos)
{

}

void printType(int valid_type, std::string s, size_t pos) {
	if (valid_type == TYPE_CHAR)
		printChar(s, pos);
	else if (valid_type == TYPE_INT)
		printInt(s, pos);
	else if (valid_type == TYPE_FLOAT)
		printFloat(s, pos);
	else if (valid_type == TYPE_DOUBLE)
		printDouble(s, pos);
}

void ScalarConverter::convert(std::string literal) {
	int valid_type = validCheck(literal);
	size_t pos = leadingSpaces(literal);
	if (infNanCheck(literal, pos) > 0)
		printInfNan(infNanCheck(literal, pos));
	else if (valid_type == INVALID_TYPE)
		return;
	else
		printType(valid_type, literal, pos);
}
