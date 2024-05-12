#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <algorithm>

struct btc_date {
	int	y;
	int m;
	int d;
};

struct btc_date_comp {
    bool operator()(const btc_date& lhs, const btc_date& rhs) const {
        return std::tie(lhs.y, lhs.m, lhs.d) < std::tie(rhs.y, rhs.m, rhs.d);
    }
};

bool operator<(const btc_date& bd1, const btc_date& bd2);

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange &assign);

	public:
		static bool checkDate(const std::string str_date, btc_date& key_date, std::string& error);
		static bool addPrice(const std::string pair, std::string& error);
		static bool checkValue(const std::string pair, std::string& error);
		static bool readPricesDBase(std::ifstream& f, std::string& error);
		static bool processValues(std::ifstream& f, std::string& error);
		
	public:
		static std::map<btc_date, unsigned int, btc_date_comp> data;
};

#endif