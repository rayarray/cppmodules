/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:41 by rleskine          #+#    #+#             */
/*   Updated: 2023/11/20 16:14:31 by rleskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		static const int	fractionalBits	= 8;
		int					fixedPoint;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed & operator = (const Fixed &fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif