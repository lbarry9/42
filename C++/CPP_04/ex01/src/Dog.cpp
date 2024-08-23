/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:03:27 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 18:53:49 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

// default constuctor
Dog::Dog(void)
{
	std::cout << "Dog's default constructor here" << std::endl;
	this->_type = "Dog";
	_brain = new Brain();
}

// parametrised constuctor
Dog::Dog(std::string type)
{
	this->_type = type;
	std::cout << "Dog's parametrised constructor here. Type = " << this->_type << std::endl;
	_brain = new Brain();
}

// copy constructor
Dog::Dog(const Dog& copy): Animal(copy)
{
	*this = copy;
	std::cout << "Dog's copy constructor here" << std::endl;
}

// destructor
Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog's destructor here" << std::endl;
}
// copy assignment operator overload
Dog	&Dog::operator=(const Dog& copy)
{
	std::cout << "Dog's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	_brain = new Brain(*copy._brain);
	return (*this);
}

// member function
void	Dog::makeSound() const
{
	std::cout << "<< WOOF WOOF >>" << std::endl;
}

// getter
std::string Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

// setter
void Dog::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}
