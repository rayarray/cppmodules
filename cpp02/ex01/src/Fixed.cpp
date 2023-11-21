/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:14:42 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/21 10:49:09 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int		Fixed::getRawBits() const { 
	//std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint; 
}

void	Fixed::setRawBits(int const raw) { 
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float	Fixed::toFloat() const {
	float	f;
	
	f = this->fixedPoint;
	f /= (1 << this->fractionalBits);
	return f;
}

int	Fixed::toInt() const {
	return static_cast<int>(this->fixedPoint / (1 << this->fractionalBits));
}