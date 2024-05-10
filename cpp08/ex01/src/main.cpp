#include "Span.hpp"
#include <vector>
#include <ctime>

struct gen_data {
	int last_nbr;
	unsigned int iter;
	unsigned int size;
	int min;
	int max;
	int method;
};

void static_tests() {
	Span test(20);
	test.addNumber(65536);
	try {
		test.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	test.addNumber(32);
	test.addNumber(42);
	test.addNumber(-42);
	test.addNumber(0);
	test.addNumber(-256); test.addNumber(34); test.addNumber(65536*2); 
	test.addNumber(5); test.addNumber(-1024);
	try {
		test.addNumber(16);
	}  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "shortest span: " << test.shortestSpan() << std::endl;
	std::cout << " longest span: " << test.longestSpan() << std::endl;
	test.print();
	test.addNumbers((int []){ -88, -55, -22, 11, 33, 55, 77, 99 }, 8);
	test.print();
	std::cout << "shortest span: " << test.shortestSpan() << std::endl;
	std::cout << " longest span: " << test.longestSpan() << std::endl;
	std::vector<int> int_vec{ -200000, 5555, 200000, 6666, 7777 };
	std::forward_list<int> int_fwd{10, 20, 30, 40, 50};
	Span ctest(100);
	ctest.addNumbers((int []){ -1, 0, 2 }, 3);
	ctest.addNumbers<std::vector<int> >(int_vec.begin(), int_vec.end());
	ctest.addNumbers<std::forward_list<int> >(int_fwd.begin(), int_fwd.end());
	ctest.print();
}

int generateNumber(gen_data *data) {
	if (data->method == 0) 
		return (data->iter++, data->min + std::rand() % (data->max + 1) - data->min);
	else if (data->method == 1)
		return (data->iter++, data->min + (((data->max - data->min) * data->iter) / data->size));
	else
		return -1;
}

int main(int ac, char **ag) {
	if (ag && ac < 2)
		return (static_tests(), 0);
	else if (ac < 4 || ac > 5)
		return (std::cout << "Usage: " << *ag << " NUM MIN MAX [METHOD]" << std::endl <<
		"where NUM is amount of numbers to generate, numbers will be generated" << std::endl <<
		"at MIN - MAX range and optional METHOD [0-1] specifies method of generation." << std::endl <<
		"0:Random, 1:Ascending" << std::endl, 0);
	std::srand(time(0));
	unsigned int size;
	int min, max, gen_method;
	try {
		long int lsize = std::stol(ag[1]);
		if (lsize > std::numeric_limits<unsigned>::max())
			throw std::out_of_range("Size is out of range!");
		size = static_cast<unsigned int>(lsize);
		min = std::stoi(ag[2]);
		max = std::stoi(ag[3]);
		gen_method = (ac == 5) ? std::stoi(ag[4]) : 0;
		if (gen_method < 0 || gen_method > 1)
			throw std::invalid_argument("Invalid method!");
	} catch (std::exception &e) {
		return (std::cout << "Invalid input: " << e.what() << std::endl, 0);
	}
	Span span_instance(size);
	int nbr_set[size];
	gen_data nbr_set_data = { 0, 0, size, min, max, gen_method };
	while (nbr_set_data.iter < nbr_set_data.size)
		nbr_set[nbr_set_data.iter] = generateNumber(&nbr_set_data);
	span_instance.addNumbers(nbr_set + 1, size);
	std::cout << "shortest span is " << span_instance.shortestSpan() << std::endl;
	std::cout << " longest span is " << span_instance.longestSpan() << std::endl;
	return 0;
}