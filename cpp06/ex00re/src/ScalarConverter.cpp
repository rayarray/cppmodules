#include "ScalarConverter.hpp"

size_t  leadingSpaces(std::string s) {
	size_t  pos = 0;
	while (pos < s.size() && s.at(pos) == ' ') {
		if (pos + 1 == s.size() && s.at(pos) == ' ')
			return pos;
		pos++;
	}
	return pos;
}

size_t charCheck(std::string s, size_t pos) {
    //std::cout << "charCheck" << std::endl;
    return (s.size() == pos + 3 && s.at(pos) == '\'' && s.at(pos + 2) == '\'');
}

size_t infNanCheck(std::string s, size_t pos) {
	if (!s.compare(pos, -1, "nan") || !s.compare(pos, -1, "+nan") || !s.compare(pos, -1, "-nan"))
		return NOTANUMBER;
	else if (!s.compare(pos, -1, "-inff"))
		return MINUS_INFF;
	else if (!s.compare(pos, -1, "+inff") || !s.compare(pos, -1, "inff"))
		return PLUS_INFF;
	else if (!s.compare(pos, -1, "-inf"))
		return MINUS_INF;
	else if (!s.compare(pos, -1, "+inf") || !s.compare(pos, -1, "inf"))
		return MINUS_INFF;
	return 0;
}

// 1 is minus, 2 is plus, 0 for no sign
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

size_t pointCheck(std::string s, size_t pos) {
	if (pos < s.size() && s.at(pos) == '.')
		return 1;
	return 0;
}

int validCheck(std::string s) {
	size_t pos = leadingSpaces(s);
	int numbers = 0, point = 0, digits = 0, fchar = 0;
	if (charCheck(s, pos))
		return TYPE_CHAR;
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
	if (pos == s.size() && numbers && !point && !digits && !fchar)
		return TYPE_INT;
	if (pos == s.size() && (numbers || (point && (digits || numbers))) && fchar)
		return TYPE_FLOAT;
	if (pos == s.size() && point && (numbers || digits) && !fchar)
		return TYPE_DOUBLE;
	return (std::cout << "Invalid input, no representation possible!" << std::endl, INVALID_TYPE);
}

void printInfNan(int special_type) {
    if (special_type == NOT_INF_NAN)
        return;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    float f = std::numeric_limits<float>::quiet_NaN();
    double d = std::numeric_limits<double>::quiet_NaN();
    if (special_type != NOTANUMBER) {
        int minusplus = (special_type == MINUS_INFF || special_type == MINUS_INF) ? -1 : 1;
        f = std::numeric_limits<float>::infinity() * minusplus;
        d = std::numeric_limits<double>::infinity() * minusplus;
    }
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl; 
}

bool printLitChar(std::string s, size_t pos) {
    if (std::isprint(s.at(pos + 1)))
        std::cout << "char: unprintable" << std::endl;
    else
        std::cout << "char: '" << s.at(pos + 1) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(s.at(pos + 1)) << std::endl;
    std::cout << "float: " << static_cast<float>(s.at(pos + 1)) << std::endl;
    std::cout << "double: " << static_cast<double>(s.at(pos + 1)) << std::endl;
    return true;
}

long double printChar(long double ld) {
    std::cout << "char: ";
    if (ld >= std::numeric_limits<char>::min() && ld <= std::numeric_limits<char>::max()) {
        if (std::isprint(static_cast<char>(ld)))
            std::cout << "'" << static_cast<char>(ld) << "'" << std::endl;
        else
            std::cout << "unprintable" << std::endl;
    } else {
        std::cout << "out of range" << std::endl;
    }
    return ld;
}

long double printInt(long double ld) {
    std::cout << "int: ";
    if (ld >= std::numeric_limits<int>::min() && ld <= std::numeric_limits<int>::max())
        std::cout << static_cast<int>(ld) << std::endl;
    else
        std::cout << "out of range" << std::endl;
    return ld;
}

long double printFloat(long double ld) {
    std::cout << "float: ";
    if (std::abs(ld) >= std::numeric_limits<float>::min() && ld <= std::numeric_limits<float>::max())
        std::cout << static_cast<float>(ld) << std::endl;
    else
        std::cout << "out of range" << std::endl;
    return ld;
}

long double printDouble(long double ld) {
    std::cout << "double: ";
    if (std::abs(ld) >= std::numeric_limits<double>::min() && ld <= std::numeric_limits<double>::max())
        std::cout << static_cast<double>(ld) << std::endl;
    else
        std::cout << "out of range" << std::endl;
    return ld;
}

bool getLongDouble(std::string s, size_t pos, long double *ld) {
    try {
        *ld = std::stold(s.substr(pos, -1));
        return true;
    } catch (std::invalid_argument const&) {
        std::cout << "Invalid input, cannot convert to number!" << std::endl;
    } catch (std::out_of_range const&) {
        std::cout << "Given number cannot be converted into any type" << std::endl; 
    }
    return false;
}

void ScalarConverter::convert(std::string literal) {
    long double ld;
    printInfNan(infNanCheck(literal, leadingSpaces(literal)));
    if (validCheck(literal) == INVALID_TYPE || 
            ((charCheck(literal, leadingSpaces(literal)) && printLitChar(literal, leadingSpaces(literal))) ||
            !getLongDouble(literal, leadingSpaces(literal), &ld)))
        return;
    printDouble(printFloat(printInt(printChar(ld))));
}