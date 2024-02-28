/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:55 by rleskine          #+#    #+#             */
/*   Updated: 2024/01/26 08:37:21 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void subjectTests()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	j->haveIdea("eat");
	i->haveIdea("sleep");
	delete j;
	delete i;
}

void deepCopyTest()
{
	// Cat catwithideas;
	const Cat *catwithideas = new Cat();
	catwithideas->haveIdea("mouse");
	catwithideas->mindRead(true);
	// Cat catwithmoreideas(catwithideas);
	const AAnimal *catwithmoreideas = new Cat(*catwithideas);
	catwithmoreideas->mindRead(true);
	catwithideas->haveIdea("sleep");
	catwithmoreideas->haveIdea("sleep");
	catwithmoreideas->haveIdea("purr");
	std::cout << "Copy assignment here" << std::endl;
	Cat catwithassignedideas;			  // making an empty cat to test copy assignment
	catwithassignedideas = *catwithideas; // copy assignment with 2 ideas
	std::cout << "\e[0;31mFinal compare, original\e[0m" << std::endl;
	catwithideas->mindRead(true);
	std::cout << "\e[0;31mFinal compare, copy construct\e[0m" << std::endl;
	catwithmoreideas->mindRead(true);
	std::cout << "\e[0;31mFinal compare, assign copy\e[0m" << std::endl;
	catwithassignedideas.mindRead(true);
	delete catwithideas;
	delete catwithmoreideas;
}

void ex02tests()
{
	// std::cout << "\e[0;44mTests code block from the subject PDF\e[0m" << std::endl;
	// subjectTests();
	// int herdSize = 10; // must be even!
	// std::cout << "\e[0;44mCreating a herd of cats and dogs the size of " << herdSize << "\e[0m" << std::endl;
	// Animal *catsdogs[herdSize];
	// for (int i = 0; i < herdSize / 2; i++)
	// 	catsdogs[i] = new Dog;
	// for (int i = herdSize / 2; i < herdSize; i++)
	// 	catsdogs[i] = new Cat;
	// std::cout << "\e[0;44mEuthanizing all animals, please close your eyes\e[0m" << std::endl;
	// for (int i = 0; i < herdSize; i++)
	// 	delete (catsdogs[i]);
	// std::cout << "\e[0;44mDeep copy tests\e[0m" << std::endl;
	// deepCopyTest();
	// std::cout << "\e[0;44mEnd\e[0m" << std::endl;
}

int main()
{
	std::cout << "\e[0;44mTests code block from the subject PDF (for previous ex.) \e[0m" << std::endl;
	subjectTests();
	std::cout << "\e[0;44mDeep copy tests\e[0m" << std::endl;
	deepCopyTest();
	std::cout << "\e[0;44mAbstract tests\e[0m" << std::endl;
	AAnimal *dog = new Dog();
	dog->mindRead(true);
	dog->haveIdea("am I abstract?");
	dog->mindRead(true);
	delete dog;
	AAnimal *cat = new Cat();
	cat->mindRead(true);
	cat->haveIdea("am I abstract?");
	cat->mindRead(true);
	delete cat;
	// std::cout << "\e[0;44mImplementing AAnimal class produces compiler errors\e[0m" << std::endl;
	// AAnimal *aanimal = new AAnimal();
	//(void)aanimal;
	std::cout << "\e[0;44mEnd\e[0m" << std::endl;
	return 0;
}
