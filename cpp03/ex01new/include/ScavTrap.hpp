/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:30:17 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:56:55 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string name = "defaultScav");
	ScavTrap(const ScavTrap &otherTrap);
	~ScavTrap();

	ScavTrap operator=(const ScavTrap &otherTrap);

	void attack(const std::string &target);
	void guardGate();

protected:
	static int scavHitPoints;
	static int scavEnergyPoints;
	static int scavAttackDamage;
};

#endif