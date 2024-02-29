#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &) {}

AMateria::~AMateria() {}

// AMateria &AMateria::operator=(const AMateria &) {}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
