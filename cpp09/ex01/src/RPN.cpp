#include "RPN.hpp"

std::stack<int> RPN::nbr_stack;

inline bool RPN::checkValidChar(const char c) {
	return (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::getTwoFromStack(int& one, int& two) {
	if (nbr_stack.size() < 2) return false;
	one = nbr_stack.top();
	nbr_stack.pop();
	two = nbr_stack.top();
	nbr_stack.pop();
	return true;
}

bool RPN::doOperation(const char c, std::string& error) {
	int result = 0, left = 0, right = 0;
	if (!getTwoFromStack(right, left)) return (error = "Cannot perform operation with 0 or 1 numbers in stack", false);
	switch (c) {
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
			if (right == 0) return (error = "Division by zero", false);
			result = left / right;
	}
	return (nbr_stack.push(result), true);
}

bool RPN::solveEquation(const std::string& eq, int& result,std::string& error) {
	bool thereWasSpace = false;
	for (unsigned int i = 0; i < eq.size(); i++) {
		if (!thereWasSpace && i != 0) {
			if (eq.at(i) != ' ')
				return (error = "Space between elements is required", false);
			thereWasSpace = true;
		}
		else if (checkValidChar(eq.at(i))) {
			if (std::isdigit(eq.at(i))) {
				nbr_stack.push(eq.at(i) - 48);
			}
			else {
				if (!doOperation(eq.at(i), error))
					return (error = "Error during operation: " + error, false);
			}
			thereWasSpace = false;
		}
		else return (error = "Invalid character or form: ' '", error[28] = eq.at(i), false);
	}
	if (nbr_stack.size() != 1) return (error = "Stack size is not 1 after solve", false);
	return (result = nbr_stack.top(), true);
}

// bool BitcoinExchange::checkDate(const std::string str_date, btc_date& key_date, std::string& error) {
// 	if (str_date.size() != 10) return (error = "Incorrect format", false);
// 	for (unsigned int i = 0; i < str_date.size(); i++) {
// 		if ((!std::isdigit(str_date.at(i)) && i != 4 && i != 7) && ((i == 4 || i == 7) && str_date.at(i) != '-'))
// 			return (error = "Invalid characters in date", false);
// 	}
// 	int y = 0, m = 0, d = 0;
// 	try {
// 		y = std::stoi(str_date.substr(0, 4));
// 		m = std::stoi(str_date.substr(5, 2));
// 		d = std::stoi(str_date.substr(8, 2));
// 	} catch (std::exception &e) {
// 		return (error = e.what(), false);
// 	}
// 	if (y < 2009 || y > 2100)
// 		return (error = "Invalid year, must be between 2009 and 2100", false);
// 	if (m < 1 || m > 12)
// 		return (error = "Invalid month", false);
// 	int valid_max_d = ((m < 8 && m % 2 == 1) || (m > 7 && m % 2 == 0)) ? 31 : 30;
// 	if (m == 2)
// 		valid_max_d = ((y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0))) ? 29 : 28;
// 	if (d < 1 || d > valid_max_d)
// 		return (error = "Invalid day of month", false);
// 	return (key_date.y = y, key_date.m = m, key_date.d = d, true);
// }
// bool BitcoinExchange::addPrice(const std::string pair, std::string& error) {
// 	if (pair.size() < 11) return (error = "Too short line in price database", false);
// 	btc_date key_date;
// 	if (!checkDate(pair.substr(0, 10), key_date, error)) return (error = "Date error: " + error, false);
// 	if (pair.at(10) != ',') return (error = "Comma separator missing", false);
// 	unsigned int price = 0, dec = 3;
// 	if (!std::isdigit(pair.at(11))) return (error = "Value did not begin with a number", false);
// 	for (unsigned int pos = 11; pos < pair.size(); pos++) {
// 		if (std::isdigit(pair.at(pos)) && (dec == 3 || (dec != 3 && dec <= 2 && dec--)))
// 			price = price * 10 + std::stoi(pair.substr(pos, 1));
// 		else if (dec == 3 && pair.at(pos) == '.') dec--;
// 		else return (error = "Error parsing value", false);
// 	}
// 	if (data.find(key_date) != data.end())
// 		return (error = "Value for date already entered", false);
// 	return (data[key_date] = price, true);
// }
// bool BitcoinExchange::checkValue(const std::string pair, std::string& error) {
// 	if (pair.size() < 14) return (error = "Too short line in value database", false);
// 	btc_date value_date;
// 	if (!checkDate(pair.substr(0, 10), value_date, error)) 
// 		return (error = "Date error: " + error, false);
// 	if (pair.substr(10, 3).compare(" | ")) return (error = "Separator characters missing", false);
// 	if (!std::isdigit(pair.at(13)) || pair.at(13) == '.')
// 		return (error = "Value did not begin with a number or a decimal point", false);
// 	float amount;
// 	try {
// 		amount = std::stof(pair.substr(13, -1));
// 	} catch (std::exception& e) {
// 		return (error = "Error parsing value: ", error += e.what(), false);
// 	}
// 	if (amount < 0) return (error = "Not a positive number", false);
// 	if (amount > 1000) return (error = "Number too large", false);
// 	auto value_on_date = data.upper_bound(value_date);
// 	if (value_on_date == data.begin()) 
// 		return (error = "Value data for " + pair.substr(0, 10) + " not found", false);
// 	return (std::cout << pair.substr(0, 10) << " => " << amount << " = " << amount/100 * value_on_date->second << std::endl, true);
// }
// bool BitcoinExchange::readPricesDBase(std::ifstream& f, std::string& error) {
// 	std::string line;
// 	if (!std::getline(f, line)) return (error = "Empty prices file" + line, false);
// 	if (line.compare("date,exchange_rate")) return (error = "Invalid prices header", false);
// 	for (int i = 2; std::getline(f, line); i++)
// 		if (!addPrice(line, error))	return (error = "Line " + std::to_string(i) + ": " + error, false);
// 	return true;
// }
// bool BitcoinExchange::processValues(std::ifstream & f, std::string& error) {
// 	std::string line;
// 	if (!std::getline(f, line)) return (error = "Empty values file" + line, false);
// 	if (line.compare("date | value")) return (error = "Invalid values header", false);
// 	for (int i = 2; std::getline(f, line); i++)
// 		if (!checkValue(line, error)) 
// 			std::cout << "Line " << std::to_string(i) << ": " << error << std::endl;
// 	return true;
// }
