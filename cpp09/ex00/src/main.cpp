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
	std::cout << "break" << std::endl;
	if (!BitcoinExchange::readPricesDBase(prices_file, error))
		if(prices_file.close(), std::cout << error << std::endl, 0)
			{ ; }
	std::ifstream values_file(values_db);
	if (!values_file) 
		return (std::cout << "Error opening values database file" << std::endl, 0);
	//std::string date = "2012-02-29";
	//btc_date key_date;
	//if (!BitcoinExchange::checkDate(date, key_date, error))
	//	std::cout << error << std::endl;
	//else
	//	std::cout << "Valid date: " << date << std::endl;
	//if (BitcoinExchange::addData("2012-02-29,125.33", error))
	//	std::cout << "Valid data added" << std::endl;
	//else
	//	std::cout << error << std::endl;
	printMap();
	if (!BitcoinExchange::checkValue("2012-03-01 | 4", error))
		std::cout << error << std::endl;

	std::map<btc_date, float> maptest;
	btc_date t = { 2000, 1, 1 };
	btc_date t2 = { 2000, 1, 2 };
	//maptest.insert(t);
	maptest[t];
	maptest[t] = 1;
	maptest[t2] = 2;
	//maptest[t];
	for (const auto& [date, value] : maptest)
		std::cout << "[" << date.y << "-" << date.m << "-" << date.d<< "] = " << value << std::endl;

}