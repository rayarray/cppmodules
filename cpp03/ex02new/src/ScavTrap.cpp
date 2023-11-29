/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:43:49 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:57:59 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ScavTrap.hpp>

int ScavTrap::scavHitPoints = 100;
int ScavTrap::scavEnergyPoints = 50;
int ScavTrap::scavAttackDamage = 20;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = scavHitPoints;
	energyPoints = scavEnergyPoints;
	attackDamage = scavAttackDamage;
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &otherTrap)
{
	name = otherTrap.name;
	hitPoints = otherTrap.hitPoints;
	energyPoints = otherTrap.energyPoints;
	attackDamage = otherTrap.attackDamage;
	std::cout << "ScavTrap " << name << " copy constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap &otherTrap)
{
	std::cout << "ScavTrap " << name << " copy assigned to " << otherTrap.name << "!" << std::endl;
	if (this == &otherTrap)
		return *this;
	this->name = otherTrap.name;
	this->hitPoints = otherTrap.hitPoints;
	this->energyPoints = otherTrap.energyPoints;
	this->attackDamage = otherTrap.attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints < 1 || energyPoints < 1)
		return;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage
			  << " points of damage!" << std::endl;
	energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode" << std::endl;
}
