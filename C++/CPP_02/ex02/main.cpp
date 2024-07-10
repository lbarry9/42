/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:38:49 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/10 17:03:56 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "------------------" << std::endl;

	std::cout << "5.05 / 2: " << Fixed(5.05f) / Fixed(2) << std::endl;
	std::cout << "5.05 * 2: " << Fixed(5.05f) * Fixed(2) << std::endl;
	std::cout << "5.05 + 2: " << Fixed(5.05f) + Fixed(2) << std::endl;
	std::cout << "5.05 - 2: " << Fixed(5.05f) - Fixed(2) << std::endl;

	std::cout << "------------------" << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " <<  ++a << std::endl;
	std::cout << "a: " <<  a << std::endl;
	std::cout << "a++: " <<  a++ << std::endl;
	std::cout << "a: " <<  a << std::endl;
	std::cout << "b: " <<  b << std::endl;

	std::cout << "------------------" << std::endl;

	std::cout << "max: " <<  Fixed::max(100.5f, 3) << std::endl;
	std::cout << "min: " <<  Fixed::min(100.5f, 3) << std::endl;

	return (0);
}
