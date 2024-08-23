/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:14:04 by marvin            #+#    #+#             */
/*   Updated: 2024/08/07 21:51:31 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

// default constuctor
Animal::Animal(void)
{
	std::cout << "Animal's default constructor here" << std::endl;
	this->_type = "Who knows";
}

// parametrised constuctor
Animal::Animal(std::string type)
{
	(void)type;
	this->_type = "Who knows";
	std::cout << "Animal's parametrised constructor here. Type = " << this->_type << std::endl;
}

// copy constructor
Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal's copy constructor here" << std::endl;
}

// destructor
Animal::~Animal(void)
{
	std::cout << "Animal's destructor here" << std::endl;
}

// copy assignment operator overload
Animal&	Animal::operator=(const Animal& copy)
{
	std::cout << "Animal's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

// getters
std::string	Animal::getType(void) const
{
	return (this->_type);
}

// member function
void	Animal::makeSound(void) const
{
	std::cout << "<< Who knows what animal sound >>" << std::endl;
}
