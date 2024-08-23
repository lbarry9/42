/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:21:57 by marvin            #+#    #+#             */
/*   Updated: 2024/08/05 14:21:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

// default constuctor
WrongCat::WrongCat(void)
{
	std::cout << "WrongCat's default constructor here" << std::endl;
	this->_type = "WrongCat";
}

// parametrised constuctor
WrongCat::WrongCat(std::string type)
{
	this->_type = type;
	std::cout << "WrongCat's parametrised constructor here. Type = " << this->_type << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	*this = copy;
	std::cout << "WrongCat's copy constructor here" << std::endl;
}

// destructor
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat's destructor here" << std::endl;
}
// copy assignment operator overload
WrongCat	&WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

// member function
void	WrongCat::makeSound() const
{
	std::cout << "<< MEOW MEOW >>" << std::endl;
}
