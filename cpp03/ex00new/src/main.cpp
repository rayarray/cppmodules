/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:01 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/29 18:53:56 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ClapTrap.hpp>

int main()
{
	ClapTrap noname;
	noname.takeDamage(10);
	ClapTrap clappy("Clappy");
	clappy.attack("dummy");
	// clappy.attack(NULL); // causes segfault, cannot fix without overloading function
	clappy.attack("");
	clappy.takeDamage(5);
	clappy.beRepaired(2);

	ClapTrap overflow("DmgOverflowTest");
	overflow.takeDamage(std::numeric_limits<int>::max() + 65536);

	ClapTrap overflow2("RepairOverFlowTest");
	overflow2.beRepaired(std::numeric_limits<int>::max() + 65536);

	ClapTrap overflow3("ExtraBigOverFlowTest");
	overflow3.takeDamage(std::numeric_limits<unsigned int>::max() - 16);

	ClapTrap copytrap(clappy);

	ClapTrap assigntrap("AssignTrap");
	assigntrap = clappy;
	assigntrap.takeDamage(10);
}
