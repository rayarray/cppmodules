/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:01 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:53:32 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>

int main()
{
	ClapTrap noname;
	noname.takeDamage(10);
	ScavTrap noname2;
	noname2.takeDamage(10);
	FragTrap noname3;
	noname3.takeDamage(10);
	FragTrap fraggy(" Fraggy");
	fraggy.attack("dummy");
	// fraggy.attack(NULL); // causes segfault, cannot fix without overloading function
	fraggy.attack("");
	fraggy.highFivesGuys();
	fraggy.takeDamage(5);
	fraggy.beRepaired(2);

	FragTrap overflow("  DmgOverflowTest");
	overflow.takeDamage(std::numeric_limits<int>::max() + 65536);

	FragTrap overflow2("   RepairOverFlowTest");
	overflow2.beRepaired(std::numeric_limits<int>::max() + 65536);

	FragTrap overflow3("    ExtraBigOverFlowTest");
	overflow3.takeDamage(std::numeric_limits<unsigned int>::max() - 16);

	FragTrap copytrap(fraggy);

	FragTrap assigntrap("     AssignTrap");
	assigntrap = fraggy;
	assigntrap.takeDamage(10);
	assigntrap.takeDamage(87);
	fraggy.takeDamage(97);
}
