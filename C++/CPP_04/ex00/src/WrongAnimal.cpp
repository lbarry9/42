/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:22:06 by marvin            #+#    #+#             */
/*   Updated: 2024/08/05 14:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

// default constuctor
WrongAnimal::WrongAnimal(void)
{
	std::cout << "Wrong Animal's default constructor here" << std::endl;
	this->_type = "Who knows";
}

// parametrised constuctor
WrongAnimal::WrongAnimal(std::string type)
{
	(void)type;
	this->_type = "Who knows";
	std::cout << "Wrong Animal's parametrised constructor here. Type = " << this->_type << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "Wrong Animal's copy constructor here" << std::endl;
}

// destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal's destructor here" << std::endl;
}

// copy assignment operator overload
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "Wrong Animal's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

// getters
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// member function
void	WrongAnimal::makeSound(void) const
{
	std::cout << "<< Wrong Animal's sound >>" << std::endl;
}
