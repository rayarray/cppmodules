/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:03:19 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 14:38:33 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void 	Harl::debug() {
	std::cout << "[DEBUG] It's a custom debug message containing debug information!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO] It's a custom info message containing informational information!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING] It's a custom warning message containing a warning!" << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR] It's a custom error message containing an error!" << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*levelfunction[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 1; i <= 4; i++)
		if (level == levels[i - 1])
			(this->*levelfunction[i - 1])();
}