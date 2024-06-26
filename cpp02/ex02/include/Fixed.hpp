/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:41 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/24 14:42:21 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int	fractionalBits	= 8;
		int					fixedPoint;
	public:
		Fixed();
		Fixed(bool debugMsg);
		Fixed(const int value);
		Fixed(const int value, bool debugMsg);
		Fixed(const float value);
		Fixed(const float value, bool debugMsg);
		Fixed(const Fixed &fixed);
		~Fixed();

		Fixed & operator = (const Fixed &fixed);
		Fixed &	operator + (const Fixed &fixed);
		Fixed & operator - (const Fixed &fixed);
		Fixed & operator * (const Fixed &fixed);
		Fixed & operator / (const Fixed &fixed);

		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	setRawBits(float const value);
		float	toFloat() const;
		int		toInt() const;
		static Fixed&	min(Fixed &fp1, Fixed &fp2);
		static const Fixed&	min(const Fixed &fp1, const Fixed &fp2);
		static Fixed&	max(Fixed &fp1, Fixed &fp2);
		static const Fixed&	max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif