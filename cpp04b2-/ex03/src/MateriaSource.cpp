/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:35:09 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/24 16:13:35 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	sources[0] = sources[1] = sources[2] = sources[3] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		sources[i] = copy.sources[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	if (this == &assign)
		return *this;
	for (int i = 0; i < 4; i++)
		sources[i] = assign.sources[i];
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (sources[i] != nullptr)
		{
			for (int j = i + 1; j < 4; j++)
				if (sources[j] == sources[i])
					sources[j] = nullptr;
			delete sources[i];
		}
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = -1;
	while (++i < 4 && sources[i] != nullptr)
		;
	if (i < 4 && sources[i] == nullptr)
		sources[i] = m->clone();
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < 4 && sources[i] != nullptr && sources[i]->getType().compare(type) != 0)
		i++;
	return ((i < 4 && sources[i] != nullptr) ? sources[i]->clone() : nullptr);
};