/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:31 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 14:58:21 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **ag)
{
	Harl		harl;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level;

	if (ac < 2) {
		harl.complain("");
		return 0;
	}
	for (level = 0; level < 4 && levels[level] != *(ag + 1); level++) {}
	switch (level) {
		case 0:
			harl.complain("DEBUG");
			level++;
		case 1:
			harl.complain("INFO");
			level++;
		case 2:
			harl.complain("WARNING");
			level++;
		case 3:
			harl.complain("ERROR");
			break;
		case 4:
			std::cout << "[unspecified] This is a custom message containing unspecified information" << std::endl;
	}
	return 0;
}