/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:06 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/24 16:15:45 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"

// Constructors
Character::Character(std::string name) : name(name)
{
	materias[0] = materias[1] = materias[2] = materias[3] = nullptr;
}

Character::Character(const Character &copy)
{
	name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		materias[i] = nullptr;
		if (copy.materias[i] != nullptr)
			materias[i] = copy.materias[i]->clone();
	}
}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (materias[i] != nullptr)
			delete materias[i];
}

// Operators
Character &Character::operator=(const Character &assign)
{
	if (this == &assign)
		return *this;
	name = assign.getName();
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != nullptr)
			delete materias[i];
		materias[i] = nullptr;
		if (assign.materias[i] != nullptr)
			materias[i] = assign.materias[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (m == nullptr)
		return;
	for (int i = 0; i < 4; i++)
		if (materias[i] == m)
			return;
	for (int i = 0; i < 4 && (i == 0 || materias[i - 1] != m); i++)
		materias[i] = (materias[i] == nullptr) ? m : materias[i];
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && materias[idx] != nullptr)
		materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && materias[idx] != nullptr)
		materias[idx]->use(target);
}

void Character::showEquip()
{
	for (int i = 0; i < 4; i++)
		if (materias[i] != nullptr)
			std::cout << "c.showEquip: " << this->getName() << " slot [" << i << "]: " << materias[i] << " " << materias[i]->getType() << std::endl;
		else
			std::cout << "c.showEquip: " << this->getName() << " slot [" << i << "] is empty" << std::endl;
}
