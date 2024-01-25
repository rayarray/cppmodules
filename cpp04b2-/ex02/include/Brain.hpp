/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:12:10 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/30 18:09:59 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define BRAIN_SIZE 100

class Brain
{
public:
	// Constructors
	Brain();
	Brain(const Brain &copy);

	// Destructor
	~Brain();

	// Operators
	Brain &operator=(const Brain &assign);

	// Getters / Setters
	void addIdea(const std::string &idea);
	void mindRead(bool showPointers = false);

private:
	std::string ideas[BRAIN_SIZE];
};

#endif