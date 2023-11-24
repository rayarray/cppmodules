/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:53:31 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:45 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <Point.hpp>

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point &copy) {
	*this = copy;
}

Point::~Point() {}

Point&	Point::operator=(const Point &other) {
	this->setXY(other.getX(), other.getX());
	return *this;
}

bool	Point::operator==(const Point &other) const {
	return (this->x == other.x && this->y == other.y);
}

Fixed&	Point::getX() const{ return this->x; }

void	Point::setXY(Fixed x, Fixed y) {
	this->x = x;
	this->y = y;
}

bool	Point::bsp(Point const a, Point const b, Point const c, Point const point) {
	if (a == b && b == c && c == point)
		return false;
	return true;
}