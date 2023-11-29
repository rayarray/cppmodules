/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:01 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:53:46 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ScavTrap.hpp>

int main()
{
	ClapTrap noname;
	noname.takeDamage(10);
	ScavTrap noname2;
	noname2.takeDamage(10);
	ScavTrap scavvy("Scavvy");
	scavvy.attack("dummy");
	// scavvy.attack(NULL); // causes segfault, cannot fix without overloading function
	scavvy.attack("");
	scavvy.guardGate();
	scavvy.takeDamage(5);
	scavvy.beRepaired(2);

	ScavTrap overflow("DmgOverflowTest");
	overflow.takeDamage(std::numeric_limits<int>::max() + 65536);

	ScavTrap overflow2("RepairOverFlowTest");
	overflow2.beRepaired(std::numeric_limits<int>::max() + 65536);

	ScavTrap overflow3("ExtraBigOverFlowTest");
	overflow3.takeDamage(std::numeric_limits<unsigned int>::max() - 16);

	ScavTrap copytrap(scavvy);

	ScavTrap assigntrap("AssignTrap");
	assigntrap = scavvy;
	assigntrap.takeDamage(10);
	assigntrap.takeDamage(87);
	scavvy.takeDamage(97);
}
