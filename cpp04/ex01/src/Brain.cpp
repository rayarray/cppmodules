/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:12:15 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 18:37:48 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;35mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "\e[0;35mCopy Constructor called of Brain\e[0m" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "\e[1;35mDestructor called of Brain\e[0m" << std::endl;
}

// Operators
Brain &Brain::operator=(const Brain &assign)
{
	std::cout << "Brain assign operator called" << std::endl;
	if (this == &assign)
		return *this;
	for (int i = 0; i < BRAIN_SIZE; i++)
		ideas[i].assign(assign.ideas[i]);
	return *this;
}

// Getters / Setters

void Brain::addIdea(const std::string &idea)
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		if (ideas[i].empty() || i == BRAIN_SIZE)
		{
			ideas[i] = idea;
			break;
		}
}

void Brain::mindRead(bool showPointers)
{
	for (int i = 0; i < BRAIN_SIZE && !ideas[i].empty(); i++)
	{
		std::cout << (i + 1) << ": ";
		if (showPointers)
			std::cout << ideas + i << " : ";
		std::cout << ideas[i] << std::endl;
	}
}
