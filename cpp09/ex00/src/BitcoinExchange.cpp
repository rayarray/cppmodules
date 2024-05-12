#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}


// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

bool BitcoinExchange::checkDate(std::string str_date, btc_date& key_date, std::string& error) {
	if (str_date.size() != 10) return (error = "Incorrect format", false);
	for (unsigned int i = 0; i < str_date.size(); i++) {
		if ((!std::isdigit(str_date.at(i) && i != 4 && i != 7)) && ((i == 4 || i == 7) && str_date.at(i) != '-'))
			return (error = "Invalid characters in date", false);
	}
	int y = 0, m = 0, d = 0;
	try {
		y = std::stoi(str_date.substr(0, 4));
		m = std::stoi(str_date.substr(5, 7));
		d = std::stoi(str_date.substr(8, 10));
	} catch (std::exception &e) {
		return (error = e.what(), false);
	}
	std::cout << y << std::endl;
	if (y < 2009 || y > 2100)
		return (error = "Invalid year, must be between 2009 and 2100", false);
	if (m < 1 || m > 12)
		return (error = "Invalid month", false);
	int valid_max_d = ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0)) ? 31 : 30;
	if (m == 2)
		valid_max_d = ((y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))) ? 29 : 28;
	if (d < 1 || d > valid_max_d)
		return (error = "Invalid day of month", false);
	return (key_date.y = y, key_date.m = m, key_date.d = d, true);
}