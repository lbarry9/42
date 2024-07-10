/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.new.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:10:46 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/10 16:56:30 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/*-------------- comparison operators ---------------*/

bool Fixed::operator<(const Fixed &input) const
{
  return (this->_fixed < input.getRawBits());
}

bool Fixed::operator>(const Fixed &input) const
{
  return (this->_fixed > input.getRawBits());
}

bool Fixed::operator<=(const Fixed &input) const
{
  return (this->_fixed <= input.getRawBits());
}

bool Fixed::operator>=(const Fixed &input) const
{
  return (this->_fixed >= input.getRawBits());
}

bool Fixed::operator==(const Fixed &input) const
{
  return (this->_fixed == input.getRawBits());
}

bool Fixed::operator!=(const Fixed &input) const
{
  return (this->_fixed != input.getRawBits());
}

/*-------------- artithmetic operators ---------------*/

Fixed	Fixed::operator+(const Fixed &input) const
{
	Fixed res;
	res.setRawBits(this->_fixed + input._fixed);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &input) const
{
	Fixed res;
	res.setRawBits(this->_fixed - input._fixed);
	return (res);
}

// (int64_t) casts into 64-bit ints before multiplication
// avoids overflow and incorrect result if done in 32-bit arithmetic
Fixed	Fixed::operator*(Fixed const &input) const
{
	Fixed res;
	res.setRawBits((int64_t)this->_fixed * (int64_t)input._fixed >> this->_frac_bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &input) const
{
	Fixed res;
	res.setRawBits(this->_fixed / input.toFloat());
	return (res);
}

/*-------------- increment / decrement operators ---------------*/

// pre increment - increments value then returns modified object
Fixed	Fixed::operator++(void)
{
	Fixed	tmp;
	_fixed++;
	tmp._fixed = _fixed;
	return (tmp);
}
// pre decrement - decrements value then returns modified object
Fixed	Fixed::operator--(void)
{
	Fixed	tmp;
	_fixed--;
	tmp._fixed = _fixed;
	return (tmp);
}
// post increment - returns the objects value then increments it
// (int) is a dummy parameter to differenciate between pre and post
// increment / decrement functions- convention in C++
Fixed	Fixed::operator++(int)
{
	Fixed	tmp;
	tmp._fixed = _fixed;
	_fixed++;
	return (tmp);
}
// post increment - returns the objects value then decrements it
Fixed	Fixed::operator--(int)
{
	Fixed	tmp;
	tmp._fixed = _fixed;
	_fixed--;
	return (tmp);
}

/*----- 4 public overloaded member functions (max, min, const max, const min)------*/

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}
Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}
Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}
