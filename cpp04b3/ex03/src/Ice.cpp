#include "Ice.hpp"

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(const Ice &copy) : AMateria(copy.getType()) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &assign)
{
	if (this == &assign)
		return *this;
	// Ice(assign.getType());
	// return *this;
	// delete this;
	// return *new Ice(assign.type);
	Ice(assign.type);
	return *this;
}

std::string const &Ice::getType() const
{
	return type;
}

AMateria *Ice::clone() const
{
	return new Ice(this->getType());
	// std::shared_ptr<AMateria> cloned = std::make_shared<Ice>();
	// return cloned.get(); // wanted to try make_shared but containers are forbidden
}

void Ice::use(ICharacter &target)
{
	std::cout << "\e[1;94m* " << type << " shoots an ice bolt at " << target.getName() << " *\e[0;37m" << std::endl;
}
