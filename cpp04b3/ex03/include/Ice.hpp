#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(std::string const &type = "ice");
	Ice(const Ice &copy);
	virtual ~Ice();

	virtual Ice &operator=(const Ice &assign);

	std::string const &getType() const;
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif /* ICE_HPP */
