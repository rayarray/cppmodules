#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(std::string const &type = "cure");
	Cure(const Cure &copy);
	virtual ~Cure();

	virtual Cure &operator=(const Cure &assign);

	std::string const &getType() const;
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif /* CURE_HPP */
