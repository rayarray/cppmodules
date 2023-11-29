/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:27:55 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:43:24 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	std::string name;

public:
	DiamondTrap(std::string name = "defaultDiamond");
	DiamondTrap(const DiamondTrap &otherTrap);
	~DiamondTrap();

	DiamondTrap operator=(const DiamondTrap &otherTrap);

	void attack(const std::string &target);
	void whoAmI();
};

#endif