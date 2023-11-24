/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:43:18 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:40 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <Fixed.hpp>

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &copy);
		~Point();

		Point & operator = (const Point &other);
		
		bool	operator==(const Point &other) const;

		Fixed&	getX() const;
		void	setXY(Fixed x, Fixed y);
		bool	bsp(Point const a, Point const b, Point const c, Point const point);
};

#endif
