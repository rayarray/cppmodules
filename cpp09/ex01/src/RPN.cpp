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
