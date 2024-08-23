/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:28:13 by marvin            #+#    #+#             */
/*   Updated: 2024/08/02 12:28:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

// default constuctor
Cat::Cat(void)
{
	std::cout << "Cat's default constructor here" << std::endl;
	this->_type = "Cat";
}

// parametrised constuctor
Cat::Cat(std::string type)
{
	this->_type = type;
	std::cout << "Cat's parametrised constructor here. Type = " << this->_type << std::endl;
}

// copy constructor
Cat::Cat(const Cat& copy): Animal(copy)
{
	*this = copy;
	std::cout << "Cat's copy constructor here" << std::endl;
}

// destructor
Cat::~Cat(void)
{
	std::cout << "Cat's destructor here" << std::endl;
}
// copy assignment operator overload
Cat	&Cat::operator=(const Cat& copy)
{
	std::cout << "Cat's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

// member function
void	Cat::makeSound() const
{
	std::cout << "<< MEOW MEOW >>" << std::endl;
}
