#include "RPN.hpp"

void showStack() {
	while (!RPN::nbr_stack.empty()) {
		std::cout << RPN::nbr_stack.top() << "->";
		RPN::nbr_stack.pop();
	}
	std::cout << std::endl;
}

int main(int ac, char **ag) {
	if (ac != 2) return (std::cout << "Please provide exactly one argument (hint: use quotes)" << std::endl, 0);
	std::string error;
	int result;
	if (!RPN::solveEquation(ag[1], result, error))
		std::cout << error << std::endl;
	else
		std::cout << result << std::endl;
	return 0;
}