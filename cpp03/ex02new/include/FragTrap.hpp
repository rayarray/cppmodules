/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:30:17 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 19:01:14 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string name = "defaultFrag");
	FragTrap(const FragTrap &otherTrap);
	~FragTrap();

	FragTrap operator=(const FragTrap &otherTrap);

	void attack(const std::string &target);
	void highFivesGuys(void);

protected:
	static int fragHitPoints;
	static int fragEnergyPoints;
	static int fragAttackDamage;
};

#endif