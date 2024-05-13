#ifndef PMERGEME_TPP
# define PMERGEME_TPP
# include "PmergeMe.hpp"

template<typename T, typename Container>
PmergeMe<T, Container>::PmergeMe() : level(0), main(), pend(), main_it(), pend_it() {}

template<typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &assign) : 
	level(assign.level + 1), main(assign.main), pend(assign.pend), main_it(assign.main_it), pend_it(assign.pend_it) {}

template<typename T, typename Container>
PmergeMe<T, Container>::~PmergeMe() {}

template<typename T, typename Container>
PmergeMe<std::pair<T, T>, Container> PmergeMe<T, Container>::nextMerge() {
	// if (main.size() > 3) {
	// 	next_merge = new PmergeMe<std::pair<T, T>, Container>;
	// 	std::cout << "next_merge allocated at address " << next_merge << std::endl;
	// }
	PmergeMe<std::pair<T, T>, Container> next_merge;
	//return next_merge;
	return PmergeMe<std::pair<T, T>, Container>();
}

template<typename T, typename Container>
void PmergeMe<T, Container>::storeValue(const int value) {
	if (main.size() == pend.size()) 
		main.insert(main.end(), value);
	else
		pend.insert(pend.end(), value);
}

template<typename T, typename Container>
void PmergeMe<T, Container>::storeValue(std::pair<T, T> pair) {
	if (main.size() == pend.size()) 
		main.insert(main.end(), pair);
	else
		pend.insert(pend.end(), pair);
}

template<typename T, typename Container>
bool PmergeMe<T, Container>::convertValues(const std::string& values, std::string& error) {
	int state = I_START;
	for (unsigned int pos = 0; pos <= values.size(); pos++) {
		if (state != I_END && state < I_OVERFLOW && (pos == values.size() || values.at(pos) == ' ')) {
			try {
				storeValue(std::stoi(values.substr(pos - state, state)));
			} catch (std::exception& e) {
				return (error = e.what(), false);
			}
			state = I_START;
		} else if (state != I_END && state < I_OVERFLOW && std::isdigit(values.at(pos))) 
			state++;
		else
			return (error = "Some error parsing arguments", false);
	}
	if (!main.empty() && main.size() > pend.size()) {
		pend.push_back(std::move(main.back()));
		main.pop_back();
	}
	return true;
}

template<typename T, typename Container>
typename Container::iterator PmergeMe<T, Container>::getPairValue(typename Container::iterator pair) {
	return getPairValue(*pair);
}

template<typename T, typename Container>
void PmergeMe<T, Container>::switchPairs() {
	main_it = main.begin();
	pend_it = pend.begin();
	for (; main_it != main.end();) {
		if (*getPairValue(main_it) > *getPairValue(pend_it))
			std::swap(*main_it, *pend_it);
		main_it++; pend_it++;
	}
}

template<typename T, typename Container>
void PmergeMe<T, Container>::sortPairs() {
	main_it = main.begin();
	pend_it = pend.begin();
	for (; main_it != main.end() && std::next(main_it) != main.end(); main++) {
		auto lowest_it = std::next(main_it);
		for (auto next_it = std::next(main_it); next_it != main.end(); next_it++) {

		}
	}
}

template<typename T, typename Container>
void PmergeMe<T, Container>::recursiveSortPairs(typename Container::iterator main_it, typename Container::iterator pend_it) {
	(void)main_it; (void)pend_it;
}

template<typename T, typename Container>
void PmergeMe<T, Container>::quickSortPairs(typename Container::iterator main_it, typename Container::iterator pend_it) {
	(void)main_it; (void)pend_it;
}

template<typename Container>
void printContainer(Container c) {
	typename Container::iterator i = c.begin();
	std::cout << "printContainer: { ";
	while (i != c.end()) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << "}" << std::endl;
}

#endif