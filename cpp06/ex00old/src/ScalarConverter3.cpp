#include "ScalarConverter.hpp"

size_t leadingSpaces(std::string s) {
	size_t pos = 0;
	while (pos < s.size() && s.at(pos) == ' ') {
		if (pos + 1 == s.size() && s.at(pos) == ' ')
			return pos;
		pos++;
	}
	return pos;
}

size_t charCheck(std::string s, size_t pos) {
	std::cout << "size:" << s.size() << " pos:" << pos << std::endl;
	//for (size_t i = 0; i < s.size(); i++)
	//	std::cout << s.at(i);
	//std::cout << std::endl;
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

size_t digitsCheck(std::string s, size_t pos) {
	while (pos < s.size() && std::isdigit(s.at(pos)))
		pos++;
	return pos; 
}

//std::string getDigits(std::string s, size_t pos) { return (s.substr(pos, digitsCheck(s, pos))); }

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

bool printConversions(int *possible, char c, int i, float f, double d, std::string strs) {
	(void)strs;
	std::cout << "char: ";
	if (possible[0] ==  1)
		std::cout << "'" << c << "'" << std::endl;
	else if (possible[0] == 0)
		std::cout << "impossible" << std::endl;
	else if (possible[0] < 0)
		std::cout << strs << std::endl;
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

void printInfNan(int special_type) {
	if (special_type == NOTANUMBER)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), "");
	else if (special_type == MINUS_INFF || special_type == MINUS_INF)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity() * -1, std::numeric_limits<double>::infinity() * -1, "");
	else if (special_type == PLUS_INFF || special_type == PLUS_INF)
		printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity(), std::numeric_limits<double>::infinity(), "");
}

void printChar(std::string s, size_t pos) {
	char c = s.at(pos + 1);
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	if (std::isprint(c))
		printConversions((int[]){1, 1, 1, 1}, c, i, f, d, "");
	else
		printConversions((int[]){0, 1, 1, 1}, c, i, f, d, "");
}

// 0 = ok, 1 = unprintable, 2 = out of range
int	castChar(int i,  char *c) {
	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max()) {
		*c = static_cast<char>(i);
		if (std::isprint(*c))
			return 0;
		return 1;
	}
	return 2;
}

void printInt(std::string s, size_t pos) {
	int possible[4] = {0, 0, 0, 0};
	char c = 0;
	int i = 0;
	try {
	i = std::stoi(s.substr(pos, -1));
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		try {

		} catch (std::invalid_argument) {
			std::cout << "Trying to convert from int, invalid argument. BYE" << std::endl;
		} catch (std::out_of_range) {
			
		}
	}
	std::cout << "i: " << i << std::endl;
	float f = static_cast<float>(i);
	double d = static_cast<float>(i);
	int char_state = castChar(i, &c);
	if (char_state == 0)
		printConversions((int[]){1, 1, 1, 1}, c, i, f, d, "");
	else if (char_state == 1)
		printConversions((int[]){-1, 1, 1, 1}, c, i, f, d, "unprintable");
	else
		printConversions((int[]){-1, 1, 1, 1}, c, i, f, d, "out of range");
}

void printFloat(std::string s, size_t pos) {
	float f = 0;
	try {
		f = std::stof(s.substr(pos, -1));
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}

void printType(int valid_type, std::string s, size_t pos) {
	if (valid_type == TYPE_CHAR)
		printChar(s, pos);
	else if (valid_type == TYPE_INT)
		printInt(s, pos);
	else if (valid_type == TYPE_FLOAT)
		printFloat(s, pos);
	else if (valid_type == TYPE_DOUBLE)
		std::cout << "not implemented" << std::endl;
	//	printDouble(s, pos);
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
