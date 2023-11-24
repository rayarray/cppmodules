/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:14:42 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/24 14:26:55 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixedPoint = 0;
	this->debugMsg = true;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(bool debugMsg) {
	this->fixedPoint = 0;
	this->debugMsg = debugMsg;
}

Fixed::Fixed(const int value) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	this->debugMsg = true;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const int value, bool debugMsg) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	this->debugMsg = debugMsg;
}

Fixed::Fixed(const float value) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	this->debugMsg = true;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const float value, bool debugMsg) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
	this->debugMsg = debugMsg;
}

Fixed::Fixed(const Fixed &fixed) {
	if (fixed.debugMsg) std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	if (this->debugMsg) std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
	if (this->debugMsg) std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed & Fixed::operator+(const Fixed &fixed) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(this->toFloat() + fixed.toFloat());
	return *this;
}

Fixed & Fixed::operator-(const Fixed &fixed) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(this->toFloat() - fixed.toFloat());
	return *this;
}

Fixed & Fixed::operator*(const Fixed &fixed) { // TODO!
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(this->toFloat() * fixed.toFloat());
	return *this;
}

Fixed & Fixed::operator/(const Fixed &fixed) { // TODO!
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(this->toFloat() / fixed.toFloat());
	return *this;
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

Fixed&	Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed prevalue = *this;
	this->setRawBits(this->getRawBits() + 1);
	return prevalue;
}

Fixed&	Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed prevalue = *this;
	this->setRawBits(this->getRawBits() - 1);
	return prevalue;
}

int		Fixed::getRawBits() const { 
	//std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint; 
}

void	Fixed::setRawBits(int const raw) { 
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

void	Fixed::setRawBits(float const value) {
	this->fixedPoint = static_cast<int>(std::round(value * (1 << fractionalBits)));
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

Fixed&	Fixed::min(Fixed &fp1, Fixed &fp2) {
	if (fp1 < fp2)
		return fp1;
	return fp2;
}

const Fixed&	Fixed::min(const Fixed &fp1, const Fixed &fp2) {
	if (fp1 < fp2)
		return fp1;
	return fp2;
}

Fixed&	Fixed::max(Fixed &fp1, Fixed &fp2) {
	if (fp1 > fp2)
		return fp1;
	return fp2;
}

const Fixed&	Fixed::max(const Fixed &fp1, const Fixed &fp2) {
	if (fp1 > fp2)
		return fp1;
	return fp2;
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
