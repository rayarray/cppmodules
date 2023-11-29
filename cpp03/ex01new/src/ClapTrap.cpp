/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:06:39 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 16:22:10 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ClapTrap.hpp>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
									   energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &otherTrap) : name(otherTrap.name), hitPoints(otherTrap.hitPoints),
												energyPoints(otherTrap.energyPoints),
												attackDamage(otherTrap.energyPoints)
{
	std::cout << "ClapTrap " << name << " copy constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

ClapTrap ClapTrap::operator=(const ClapTrap &otherTrap)
{
	std::cout << "ClapTrap " << name << " copy assigned to " << otherTrap.name << "!" << std::endl;
	if (this == &otherTrap)
		return *this;
	this->name = otherTrap.name;
	this->hitPoints = otherTrap.hitPoints;
	this->energyPoints = otherTrap.energyPoints;
	this->attackDamage = otherTrap.attackDamage;
	return *this;
	// return ClapTrap(otherTrap);
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints < 1 || energyPoints < 1)
		return;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
			  << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < 1 || amount == 0)
		return;
	long int overkill = static_cast<long int>(amount) - hitPoints;
	std::cout << "ClapTrap " << name << " is damaged for ";
	if (overkill < 0)
	{
		std::cout << amount << " hit points!" << std::endl;
		hitPoints -= amount;
	}
	else
	{
		std::cout << hitPoints << " (" << overkill << " overkill) points of damage!" << std::endl;
		hitPoints = 0;
	}
	if (!hitPoints)
		std::cout
			<< "ClapTrap " << name << " has taken too much damage and has shut down!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints < 1 || this->energyPoints < 1)
		return;
	long int overheal = amount + hitPoints;
	std::cout << "ClapTrap " << name << " repairs itself for ";
	if (overheal > static_cast<long int>(std::numeric_limits<int>::max()))
	{
		std::cout << std::numeric_limits<int>::max() - hitPoints << " (";
		std::cout << overheal - std::numeric_limits<int>::max() << " overheal) hit points!" << std::endl;
		hitPoints = std::numeric_limits<int>::max();
	}
	else
	{
		std::cout << amount << " hit points!" << std::endl;
		hitPoints += amount;
	}
	this->energyPoints--;
}
