/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:47:30 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/29 12:32:27 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int subjectTests()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *ice = new Ice();
	src->learnMateria(ice);
	delete ice;
	AMateria *cure = new Cure();
	src->learnMateria(cure);
	delete cure;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

int main()
{
	// subjectTests(); return 0;
	AMateria *ice = new Ice();
	Ice frost = Ice("frost");
	Ice frost2 = frost;
	Ice frost3;
	frost3 = frost;
	AMateria *cure = new Cure();
	std::cout << "Ice copy constructor: frost: " << &frost << " frost2: " << &frost2 << std::endl;
	std::cout << "Ice copy assign: frost: " << &frost << " frost3: " << &frost3 << std::endl;
	ICharacter *player1 = new Character("Iceman");
	ICharacter *player2 = new Character("target dummy");
	IMateriaSource *matsrc = new MateriaSource();
	matsrc->learnMateria(ice);
	matsrc->learnMateria(ice);
	matsrc->learnMateria(&frost2);
	matsrc->learnMateria(cure);
	std::cout << "main:break" << std::endl;
	player1->equip(matsrc->createMateria("ice"));
	std::cout << "eq1" << std::endl;
	player1->equip(matsrc->createMateria("frost"));
	std::cout << "eq2" << std::endl;
	player1->equip(matsrc->createMateria("cure"));
	AMateria *unequiptest = matsrc->createMateria("frost");
	player1->equip(unequiptest);
	player1->equip(cure); // inventory is full, if createMateria used here, will leak
	std::cout << "materias equipped" << std::endl;
	player1->use(0, *player1); // ice to self
	player1->use(1, *player1); // frost to self
	player1->use(2, *player1); // cure to self
	player1->use(2, *player2); // cure to dummy
	player2->use(0, *player1); // should not do anything
	player1->unequip(3);
	delete unequiptest;
	dynamic_cast<Character *>(player1)->showEquip();
	Character player3 = *(dynamic_cast<Character *>(player1)); // copy constructor test
	player3.showEquip();
	Character player4;
	player4 = *(dynamic_cast<Character *>(player1)); // assign operator test
	player4.showEquip();
	MateriaSource matsrc_copycns = *dynamic_cast<MateriaSource *>(matsrc); // copy constructor test
	MateriaSource matsrc_copyass;
	matsrc_copyass = *dynamic_cast<MateriaSource *>(matsrc); // copy assignment test
	dynamic_cast<MateriaSource *>(matsrc)->showSources("\e[1;31m");
	matsrc_copycns.showSources("\e[1;32m");
	matsrc_copyass.showSources("\e[1;33m");
	MateriaSource defconst;
	defconst.showSources("\e[1;34m");
	delete player1;
	delete player2;
	delete ice;
	delete cure;
	delete matsrc;
	return 0;
}
