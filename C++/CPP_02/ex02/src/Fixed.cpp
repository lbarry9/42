/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:40:19 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/10 15:24:02 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	_fixed = value << _frac_bits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(value * (1 << _frac_bits));
}

int	Fixed::toInt(void) const
{
  return (this->_fixed >> this->_frac_bits);
}

float Fixed::toFloat(void) const
{
	float	raw = (float)this->_fixed / (1 << this->_frac_bits);
	return ((raw));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

Fixed&	Fixed::operator=(const Fixed& value)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &value)
		return (*this);
	_fixed = value.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_fixed);
}

void Fixed::setRawBits(int const raw)
{
	_fixed = raw;
}

