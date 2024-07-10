/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:40:19 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/09 00:31:34 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
#include <iostream>

class Fixed
{
	private:
		int					_fixed;
		static const int	_frac_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &value);
		Fixed&	operator=(const Fixed& value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
