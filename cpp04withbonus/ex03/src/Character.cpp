/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:11:06 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/22 17:49:57 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"

// Constructors
Character::Character(std::string name) : name(name)
{
	materias[0] = materias[1] = materias[2] = materias[3] = nullptr;
}

Character::Character(const ICharacter &copy)
{
	(void)copy; // TODO
}

// Destructor
Character::~Character() {}

// Operators
ICharacter &Character::operator=(const ICharacter &assign)
{
	(void)assign; // TODO
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
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
