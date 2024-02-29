#include "MateriaCollector.hpp"

MateriaCollector::MateriaCollector() : materia(), next()
{
	if (next == nullptr)
		std::cout << "next == nullptr" << std::endl;
}

MateriaCollector::MateriaCollector(AMateria &m) : materia(&m), next() {}

MateriaCollector::MateriaCollector(const MateriaCollector &copy)
{
	materia = copy.materia;
	next = copy.next;
}

MateriaCollector::~MateriaCollector()
{
	if (materia != nullptr)
		delete materia;
	if (next != nullptr)
		next->~MateriaCollector();
}

AMateria *MateriaCollector::collect(AMateria *m)
{
	std::cout << "collect called" << std::endl;
	if (m == nullptr)
		return nullptr;
	if (materia == nullptr)
	{
		materia = m;
		std::cout << "collect: break (materia = m)" << std::endl;
	}
	else
	{
		MateriaCollector *end = this;
		std::cout << "collect: break (MC *end = next)" << std::endl;
		while (end->next != nullptr)
		{
			std::cout << "trying end = end->next" << std::endl;
			end = end->next;
		}
		std::cout << "collect: break (while !end->next (end = end->next))" << std::endl;
		end->next = new MateriaCollector(*m);
	}
	std::cout << "collect: break" << std::endl;
	return m;
}
