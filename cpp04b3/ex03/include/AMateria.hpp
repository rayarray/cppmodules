#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string const type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	virtual ~AMateria();

	// virtual AMateria &operator=(const AMateria &assign); // cannot declare in abstract class
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#include "ICharacter.hpp"

#endif /* AMATERIA_HPP */
