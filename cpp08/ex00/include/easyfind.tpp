#include "easyfind.hpp"

template<typename T>
int	&easyfind(T &container, int value) {
	(void)value;
	for (size_t i = 0; i < container.size(); i++)
		if (container[i] == value)
			return container[i];
	//return container[0];
	throw std::invalid_argument("easyfind: argument not found in container");
}
