/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:10:46 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/10 16:35:33 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

// const int constructor --> fixed point (frac bits init to 8)
// Shifting left by 8 bits is equivalent to multiplying by 2^8 (or 256).
// This effectively converts the integer to a fixed-point format by adding 8 fractional bits,
// placing the int value into the correct position in the fixed-point representation.
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed = value << _frac_bits;
}

// const float constructor --> fixed point (frac bits init to 8)
// The floating-point value is multiplied by 2^_frac_bits (or 256).
// This scales the float into fixed point by converting fractional part
// into an int. roundf rounds the result to the nearest int, keeping accuracy.
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(value * (1 << _frac_bits));
}

// fixed point -> int converter
// shift to the right 8 bits (opposite of int -> fixed constructor)
int	Fixed::toInt(void) const
{
  return (this->_fixed >> this->_frac_bits);
}

// fixed point -> float converter
// cast to float so the division handles fractional part correctly
// fixed point divided by 2^_frac_bits (or 256)
// reverses the scaling done in float -> fixed constructor
float Fixed::toFloat(void) const
{
	float	raw = (float)this->_fixed / (1 << this->_frac_bits);
	return ((raw));
}

// takes in fixed point num + output stream, and outputs float into stream
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

/* ------------------------- prev ---------------------------*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed&	Fixed::operator=(const Fixed& value)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

