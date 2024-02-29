#include "Cure.hpp"

Cure::Cure(std::string const &type) : AMateria(type)
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType()) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &assign)
{
	if (this == &assign)
		return *this;
	Cure(assign.getType());
	return *this;
}

std::string const &Cure::getType() const
{
	return type;
}

AMateria *Cure::clone() const
{
	return new Cure(this->getType());
}

void Cure::use(ICharacter &target)
{
	std::cout << "\e[1;92m* " << type << " heals " << target.getName() << "'s wounds *\e[0;37m" << std::endl;
}
