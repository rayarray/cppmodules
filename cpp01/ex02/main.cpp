/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:11:29 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/27 14:05:13 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main() {
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	std::cout << "memory address of the stringVAR: " << &stringVAR << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "the value of the stringVAR: " << stringVAR << std::endl;
	std::cout << "the value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "the value pointed to by stringREF: " << stringREF << std::endl;

	// Testing again when setting stringREF to a new string

	// std::cout << std::endl;
	// std::cout << "stringREF = \"HI THIS IS BRIAN\"" << std::endl;
	// stringREF = "HI THIS IS BRIAN";
	// std::cout << "memory address of the stringVAR: " << &stringVAR << std::endl;
	// std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	// std::cout << "memory address held by stringREF: " << &stringREF << std::endl;
	// std::cout << std::endl;
	// std::cout << "the value of the stringVAR: " << stringVAR << std::endl;
	// std::cout << "the value pointed to by stringPTR: " << *stringPTR << std::endl;
	// std::cout << "the value pointed to by stringREF: " << stringREF << std::endl;
}