/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:43:49 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 19:02:14 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <FragTrap.hpp>

int FragTrap::fragHitPoints = 100;
int FragTrap::fragEnergyPoints = 100;
int FragTrap::fragAttackDamage = 30;

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = fragHitPoints;
	energyPoints = fragEnergyPoints;
	attackDamage = fragAttackDamage;
	std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &otherTrap)
{
	name = otherTrap.name;
	hitPoints = otherTrap.hitPoints;
	energyPoints = otherTrap.energyPoints;
	attackDamage = otherTrap.attackDamage;
	std::cout << "FragTrap " << name << " copy constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &otherTrap)
{
	std::cout << "FragTrap " << name << " copy assigned to " << otherTrap.name << "!" << std::endl;
	if (this == &otherTrap)
		return *this;
	this->name = otherTrap.name;
	this->hitPoints = otherTrap.hitPoints;
	this->energyPoints = otherTrap.energyPoints;
	this->attackDamage = otherTrap.attackDamage;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (hitPoints < 1 || energyPoints < 1)
		return;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage
			  << " points of damage!" << std::endl;
	energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}
