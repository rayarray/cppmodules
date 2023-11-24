/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:23:12 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/24 14:53:09 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main() {
	Point a(Fixed(0), Fixed(5));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(0));
	Point point(Fixed(2), Fixed(2));
	Point bspcheck;
	bspcheck.bsp(a, b, c, point);
	return 0;
}
