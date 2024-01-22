/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:55 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 16:14:35 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void animalTests()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\e[0;44mDeleting objects created with new\e[0m" << std::endl;
	delete (meta);
	delete (j);
	delete (i);
}

void wrongAnimalTests()
{
	const WrongAnimal *meta = new WrongAnimal();
	// const Animal *j = new Dog();
	const WrongAnimal *i = new WrongCat();
	// std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	// j->makeSound();
	meta->makeSound();
	std::cout << "\e[0;44mDeleting objects created with new\e[0m" << std::endl;
	delete (meta);
	// delete (j);
	delete (i);
}

void mostCompleteTests()
{
	WrongCat wrongcat;
	wrongcat.makeSound();
	Animal *animalptr = new Animal();
	Animal *catptr = new Cat();
	Animal cat_animal(*catptr);
	Cat copycat;
	std::cout << "&copycat = " << &copycat << std::endl;
	copycat = Cat();
	std::cout << "&copycat = " << &copycat << std::endl;
	std::cout << "animalptr type: " << animalptr->getType() << " and sound:" << std::endl;
	animalptr->makeSound();
	std::cout << "catptr type: " << catptr->getType() << " and sound:" << std::endl;
	catptr->makeSound();
	std::cout << "Animal cat_animal(*catptr) type: " << cat_animal.getType() << " and sound:" << std::endl;
	catptr->makeSound();
	std::cout << "\e[0;44mDeleting objects created with new\e[0m" << std::endl;
	delete (animalptr);
	delete (catptr);
}

int main()
{
	std::cout << "\e[0;44mTests code block from the subject PDF\e[0m" << std::endl;
	animalTests();
	std::cout << "\e[0;44mTests code block from the subject PDF modified to use WrongAnimal and WrongCat\e[0m" << std::endl;
	wrongAnimalTests();
	std::cout << "\e[0;44mTests for copy constructor and copy assignment\e[0m" << std::endl;
	mostCompleteTests();
	std::cout << "\e[0;44mEnd\e[0m" << std::endl;
}
