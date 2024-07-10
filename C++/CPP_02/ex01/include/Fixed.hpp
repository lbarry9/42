/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:40:19 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/09 01:04:58 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed;
		static const int	_frac_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &value);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream	&operator<<(std::ostream &out, const Fixed &num);

#endif
