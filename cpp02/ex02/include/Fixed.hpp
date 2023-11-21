/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:41 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/21 12:17:55 by rleskine         ###   ########.fr       */
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
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);

		Fixed & operator = (const Fixed &fixed);
		Fixed &	operator + (const Fixed &fixed);
		Fixed & operator - (const Fixed &fixed);
		Fixed & operator * (const Fixed &fixed);
		Fixed & operator / (const Fixed &fixed);

		bool	operator==(const Fixed &other);
		bool	operator!=(const Fixed &other);
		bool	operator <(const Fixed &other);
		bool	operator<=(const Fixed &other);
		bool	operator >(const Fixed &other);
		bool	operator>=(const Fixed &other);

		void	operator++();
		Fixed	operator++(int);
		void	operator--();
		Fixed	operator--(int);
		
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		static Fixed&	min(Fixed &fp1, Fixed &fp2);
		static Fixed&	min(const Fixed &fp1, const Fixed &fp2);
		static Fixed&	max(Fixed &fp1, Fixed &fp2);
		static Fixed&	max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif