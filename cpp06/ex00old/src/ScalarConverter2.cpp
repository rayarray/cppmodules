#include "ScalarConverter.hpp"

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
    if (s.size() == pos + 3 && s.at(pos) == '\'' && std::isprint(s.at(pos + 1)) && s.at(pos + 2) == '\'')
        return 2;
    return 0;
}

// 0 = not special, 1 = nan, 2 = -inff, 3 = inff, 4 = -inf, 5 = inf
size_t infNanCheck(std::string s, size_t pos) {
    if (!s.compare(pos, -1, "nan") || !s.compare(pos, -1, "+nan") || !s.compare(pos, -1, "-nan")) return 1;
    if (!s.compare(pos, -1, "-inff")) return 2;
    if (!s.compare(pos, -1, "+inff") || !s.compare(pos, -1, "inff")) return 3;
    if (!s.compare(pos, -1, "-inf")) return 4;
    if (!s.compare(pos, -1, "+inf") || !s.compare(pos, -1, "inf")) return 5;
    return 0;
}

size_t signCheck(std::string s, size_t pos) {
    if (s.size() > pos) {
        if (s.at(pos) == '-') return 1;
        else if (s.at(pos) == '+') return 2;
    } return 0;
}

size_t digitsCheck(std::string s, size_t pos) {
    while (pos < s.size() && std::isdigit(s.at(pos))) pos++;
    return pos;
}

std::string getDigits(std::string s, size_t pos) { return (s.substr(pos, digitsCheck(s, pos))); }

size_t pointCheck(std::string s, size_t pos) {
    if (pos < s.size() && s.at(pos) == '.') return 1;
    return 0;
}

// returns 0 if not valid, 1 for char, 2 for int, 3 for float, 4 for double
int validCheck(std::string s) {
    size_t pos = leadingSpaces(s);
    int numbers = 0, point = 0, digits = 0, fchar = 0;
    if (charCheck(s, pos)) return 1;
    if (signCheck(s, pos) > 0) pos++;
    if (digitsCheck(s, pos) > pos && ++numbers) pos = digitsCheck(s, pos);
    if (pointCheck(s, pos) && ++point) pos++;
    if (digitsCheck(s, pos) > pos && ++digits) pos = digitsCheck(s, pos);
    if (pos < s.size() && s.at(pos) == 'f' && ++pos) fchar++;
    if (numbers && !point && !digits && !fchar) return 2;
    if ((numbers || (point && (digits || numbers))) && fchar) return 3;
    if (point && (numbers || digits) && !fchar) return 4;
    return (std::cout << "Invalid input, no representation possible!" << std::endl, pos + 1 == s.size());
}

bool printConversions(int *possible, char c, int i, float f, double d)
{
    (void)(d + f + i + c);
    (void)possible;
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
    if (possible[2])
    {
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

void convertFromLongDouble(std::string s, bool *print_i, int *i, bool *print_f, float *f, bool *print_d, double *d)
{
    if (print_i && i && print_f && f && print_d && d) // debug
        (void)0;                                      // debug
    long double ld = 0;
    try
    {
        ld = std::stold(s);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        *d = std::stod(s);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        *f = std::stof(s);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::string str_ld = std::to_string(ld);
    std::string str_d = std::to_string(*d);
    std::cout << "convFromLD ld and d string compare:" << str_ld.compare(str_d) << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;
    bool print_i = false, print_f = false, print_d = false;
    std::string txt_c, txt_i, txt_f, txt_d;
    int valid_type = validCheck(literal);
    std::cout << "validCheck type: " << valid_type << std::endl;
    size_t pos = leadingSpaces(literal);
    if (infNanCheck(literal, pos) == 1)
        printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::quiet_NaN(),
                         std::numeric_limits<double>::quiet_NaN());
    if (infNanCheck(literal, pos) == 2 || infNanCheck(literal, pos) == 4)
        printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity() * -1,
                         std::numeric_limits<double>::infinity() * -1);
    if (infNanCheck(literal, pos) == 3 || infNanCheck(literal, pos) == 5)
        printConversions((int[]){0, 0, 1, 1}, 0, 0, std::numeric_limits<float>::infinity(),
                         std::numeric_limits<double>::infinity());
    if (valid_type == INVALID_TYPE)
        return;
    std::stringstream ss(literal);
    if (valid_type == TYPE_CHAR) {
        ss >> c;
        if (charCheck(literal, pos) == 2)
            printConversions((int[]){1, 0, 0, 0}, literal.at(pos + 1), i, f, d);
        else {
            if (std::isdigit(literal.at(0))) {
                ss >> f;
                convertFromLongDouble(literal, &print_i, &i, &print_f, &f, &print_d, &d);
                std::cout << "Ambiguous literal. Is it a number literal or a char "
                             "literal? Printing both cases, first as number literal"
                          << std::endl;
                printConversions((int[]){0, 1, 1, 1}, c, i, f, d);
            }
            printConversions((int[]){1, 0, 0, 0}, c, 0, 0, 0);
        }
    }
    else if (valid_type == TYPE_INT) {
        std::cout << "debug ype int" << std::endl;
        convertFromLongDouble(literal, &print_i, &i, &print_f, &f, &print_d, &d);
        ss >> d;
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            printConversions((int[]){0, 0, 1, 1}, -1, d, d, d);
        else {
            if (d < std::numeric_limits<char>::min() && d > std::numeric_limits<char>::max())
                printConversions((int[]){0, 1, 1, 1}, c, d, d, d);
            else
                printConversions((int[]){1, 1, 1, 1}, c, d, d, d);
        }
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
// 		std::cout << "Special case! Plus (+) or minus (-) followed by f.
// Defaulting to zero (0)" << std::endl; 	if (*literal.rbegin() == '.') 		std::cout
// << "Special case! Last number is a decimal point. Defaulting to ignoring it"
// << std::endl;
// }

void sc_cast(std::string literal)
{
    // std::is_literal_type()
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
