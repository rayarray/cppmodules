/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:06:39 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/27 17:34:48 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ClapTrap.hpp>

ClapTrap::ClapTrap(std::string name) : name(name) {
	std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &otherTrap) : name(otherTrap.name) {
	std::cout << "ClapTrap " << name << " copy constructed!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &otherTrap) {
	this->name = otherTrap.name;
	this->hitPoints = otherTrap.hitPoints;
	this->energyPoints = otherTrap.energyPoints;
	this->attackDamage = otherTrap.attackDamage;
	std::cout << "ClapTrap " << name << " copy assigned!" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hitPoints < 1 || this->energyPoints < 1) return;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage
			  << "points of damage!" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints < 1 || amount > 0) return;
	std::cout << "ClapTrap " << this->name << " is damaged for " << amount << " points of damage!" << std::endl;
	int	checkOverflow = this->hitPoints - amount;
	if (checkOverflow > this->hitPoints)
		amount = this->hitPoints;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints < 1 || this->energyPoints < 1) return;
	int	checkOverflow = this->hitPoints + amount;
	if (checkOverflow < 0)
		amount = INT_MAX - this->hitPoints;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}
