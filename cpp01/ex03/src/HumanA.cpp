/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:02:13 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/16 15:13:28 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : name(name), weapon(weapon) {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}
