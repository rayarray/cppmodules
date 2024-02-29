#ifndef MATERIACOLLECTOR_HPP
#define MATERIACOLLECTOR_HPP

#include "AMateria.hpp"

class MateriaCollector
{
private:
	AMateria *materia;
	MateriaCollector *next;

public:
	MateriaCollector();
	MateriaCollector(AMateria &m);
	MateriaCollector(const MateriaCollector &copy);
	~MateriaCollector();

	MateriaCollector &operator=(const MateriaCollector &assign);

	AMateria *collect(AMateria *m);
};

#endif
