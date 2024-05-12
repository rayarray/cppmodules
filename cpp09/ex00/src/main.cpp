#include <string.h>
#include "BitcoinExchange.hpp"

void printMap() {
	for (const auto& [date, value] : BitcoinExchange::data)
		std::cout << "[" << date.y << "-" << date.m << "-" << date.d<< "] = " << value << std::endl;
}

int main (int ac, char **ag) {
	if (ac != 2) {
		return (std::cout << "Please provide an input file as argument to process" << std::endl, 0);
	}
	std::string prices_db = "data.csv";
	std::string values_db = ag[1];
	std::ifstream prices_file(prices_db);
	if (!prices_file) 
		return (std::cout << "Error opening prices database file: " << strerror(errno) << std::endl, 0);
	std::string error;
	if (!BitcoinExchange::readPricesDBase(prices_file, error))
		return (prices_file.close(), std::cout << error << std::endl, 0);
	std::ifstream values_file(values_db);
	if (!values_file) 
		return (std::cout << "Error opening values database file" << std::endl, 0);
	if (!BitcoinExchange::processValues(values_file, error))
		return (values_file.close(), std::cout << error << std::endl, 0);
	return (prices_file.close(), values_file.close(), 0);
}