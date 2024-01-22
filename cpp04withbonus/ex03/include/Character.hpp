#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string name;
	AMateria *materias[4];

public:
	// Constructors
	Character(std::string name = "unnamed");
	Character(const ICharacter &copy);

	// Destructor
	virtual ~Character();

	ICharacter &operator=(const ICharacter &assign);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};

#endif /* CHARACTER_HPP */