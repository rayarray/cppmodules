#include "BitcoinExchange.hpp"

std::map<int[3], unsigned int> BitcoinExchange::data;

bool operator<(const btc_date& bd1, const btc_date& bd2) {
	return (bd1.y < bd2.y || (bd1.y == bd2.y && bd1.m < bd2.m) || (bd1.y < bd2.y && bd1.m < bd2.m && bd1.d < bd2.d));
}
bool operator==(const btc_date& bd1, const btc_date& bd2) {
	return (bd1.y == bd2.y && bd1.m == bd2.m && bd1.d == bd2.d);
}

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
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

bool BitcoinExchange::checkDate(const std::string str_date, btc_date& key_date, std::string& error) {
	if (str_date.size() != 10) return (error = "Incorrect format", false);
	for (unsigned int i = 0; i < str_date.size(); i++) {
		if ((!std::isdigit(str_date.at(i)) && i != 4 && i != 7) && ((i == 4 || i == 7) && str_date.at(i) != '-'))
			return (error = "Invalid characters in date", false);
	}
	int y = 0, m = 0, d = 0;
	try {
		y = std::stoi(str_date.substr(0, 4));
		m = std::stoi(str_date.substr(5, 2));
		d = std::stoi(str_date.substr(8, 2));
	} catch (std::exception &e) {
		return (error = e.what(), false);
	}
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

bool BitcoinExchange::addPrice(const std::string pair, std::string& error) {
	if (pair.size() < 11) return (error = "Too short line in price database", false);
	btc_date key_date;
	if (!checkDate(pair.substr(0, 10), key_date, error)) return (error = "Date error: " + error, false);
	if (pair.at(10) != ',') return (error = "Comma separator missing", false);
	unsigned int price = 0, dec = 3;
	if (!std::isdigit(pair.at(11))) return (error = "Value did not begin with a number", false);
	for (unsigned int pos = 11; pos < pair.size(); pos++) {
		if (std::isdigit(pair.at(pos)) && (dec == 3 || (dec != 3 && dec <= 2 && dec--)))
			price = price * 10 + std::stoi(pair.substr(pos, 1));
		else if (dec == 3 && pair.at(pos) == '.') dec--;
		else return (error = "Error parsing value", false);
	}
	if (data.find(key_date) != data.end())
		return (std::cout << key_date.y << "-" << key_date.m << "-" << key_date.d << std::endl, error = "Value for date already entered", false);
	return (std::cout << key_date.y << "-" << key_date.m << "-" << key_date.d << std::endl, data[key_date] = price, true);
}

bool BitcoinExchange::checkValue(const std::string pair, std::string& error) {
	if (pair.size() < 14) return (error = "Too short line in value database", false);
	btc_date value_date;
	if (!checkDate(pair.substr(0, 10), value_date, error)) 
		return (error = "Date error: " + error, false);
	std::cout << pair.substr(10, 3) << std::endl;
	if (pair.substr(10, 3).compare(" | ")) return (error = "Separator characters missing", false);
	std::cout << pair.at(13) << std::endl;
	if (!std::isdigit(pair.at(13)) || pair.at(13) == '.')
		return (error = "Value did not begin with a number or a decimal point", false);
	float amount;
	try {
		amount = std::stof(pair.substr(13, -1));
	} catch (std::exception& e) {
		return (error = "Error parsing value: ", error += e.what(), false);
	}
	if (amount < 0) return (error = "Not a positive number", false);
	if (amount > 1000) return (error = "Number too large", false);
	auto value_on_date = data.upper_bound(value_date);
	if (value_on_date == data.begin()) 
		return (error = "Value data for " + pair.substr(0, 10) + " not found", false);
	std::cout << (--value_on_date)->second << std::endl;
	return (std::cout << pair.substr(0, 10) << " => " << amount << " = " << amount/100 * value_on_date->second << std::endl, true);
}

bool BitcoinExchange::readPricesDBase(std::ifstream& f, std::string& error) {
	std::string line;
	std::cout << "readpricesdbase called" << std::endl;
	if (!std::getline(f, line)) return (error = "Empty prices file" + line, false);
	std::cout << "header is read" << std::endl;
	if (line.compare("date,exchange_rate")) return (error = "Invalid prices header", false);
	for (int i = 2; std::getline(f, line); i++) {
		std::cout << line << std::endl;
		if (!addPrice(line, error))	return (error = "Line " + std::to_string(i) + ": " + error, false);
	}
	return true;
}