/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:47:30 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/22 17:18:56 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main(void)
{
	AMateria *ice = new Ice("ice");
	ICharacter *player1 = new Character("Iceman");
	player1->equip(ice);
	player1->use(0, *player1);
	// std::cout << ice->getType() << std::endl;
	delete ice;
}