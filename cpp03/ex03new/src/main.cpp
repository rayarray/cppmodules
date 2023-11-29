/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:01 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:52:21 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap noname;
	noname.takeDamage(10);
	ScavTrap noname2;
	noname2.takeDamage(10);
	FragTrap noname3;
	noname3.takeDamage(10);
	DiamondTrap noname4;
	noname4.takeDamage(10);
	DiamondTrap carbon(" Carbon");
	carbon.attack("dummy");
	// carbon.attack(NULL); // causes segfault, cannot fix without overloading function
	carbon.attack("");
	carbon.whoAmI();
	carbon.takeDamage(5);
	carbon.beRepaired(2);

	DiamondTrap overflow("  DmgOverflowTest");
	overflow.takeDamage(std::numeric_limits<int>::max() + 65536);

	DiamondTrap overflow2("   RepairOverFlowTest");
	overflow2.beRepaired(std::numeric_limits<int>::max() + 65536);

	DiamondTrap overflow3("    ExtraBigOverFlowTest");
	overflow3.takeDamage(std::numeric_limits<unsigned int>::max() - 16);

	DiamondTrap copytrap(carbon);

	DiamondTrap assigntrap("     AssignTrap");
	assigntrap = carbon;
	assigntrap.takeDamage(10);
	assigntrap.takeDamage(87);
	carbon.takeDamage(97);
}
