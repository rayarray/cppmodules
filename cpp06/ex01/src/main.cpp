#include "Serializer.hpp"

int main(int ac, char **ag) {
	Data data = (Data){42};
	if (ac == 2) {
		try {
			data = (Data){ std::stoi(*(ag + 1)) };
		} catch (std::exception &e) {
			return (std::cout << "cap'n, tellyporta cannae take any o' this!" << std::endl, 0);
		}
	}

	std::cout << "it's a [" << data.nbr << "], congratulations!" << std::endl;

	std::cout << "beam it up, scotty!" << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << "beam it down, scotty!" << std::endl;
	Data whatcamethroughtheteleporter = *Serializer::deserialize(serialized);

	std::cout << "look what we have here: [" << whatcamethroughtheteleporter.nbr << "]" << std::endl;
}