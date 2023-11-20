/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:31 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 14:37:49 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("nomatch");
}