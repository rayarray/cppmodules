/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:43:49 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 19:08:30 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	hitPoints = fragHitPoints;
	energyPoints = scavEnergyPoints;
	attackDamage = fragAttackDamage;
	std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &otherTrap)
{
	name = otherTrap.name;
	ClapTrap::name = otherTrap.ClapTrap::name;
	hitPoints = otherTrap.hitPoints;
	energyPoints = otherTrap.energyPoints;
	attackDamage = otherTrap.attackDamage;
	std::cout << "DiamondTrap " << name << " copy constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destroyed!" << std::endl;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &otherTrap)
{
	std::cout << "DiamondTrap " << name << " copy assigned to " << otherTrap.name << "!" << std::endl;
	if (this == &otherTrap)
		return *this;
	this->name = otherTrap.name;
	this->ClapTrap::name = otherTrap.ClapTrap::name;
	this->hitPoints = otherTrap.hitPoints;
	this->energyPoints = otherTrap.energyPoints;
	this->attackDamage = otherTrap.attackDamage;
	return *this;
	// return DiamondTrap(otherTrap);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << name << "'s ClapTrap name is " << ClapTrap::name << std::endl;
}