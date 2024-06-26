#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria *sources[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &assign);

	virtual void learnMateria(AMateria *m);
	virtual AMateria *createMateria(std::string const &type);
	virtual void showSources(std::string color);
};

#endif /* MATERIASOURCE_HPP */