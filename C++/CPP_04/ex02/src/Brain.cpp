/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:05:52 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 18:59:12 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

// default constuctor
Brain::Brain(void)
{
	std::cout << "Brain's default constructor here" << std::endl;
}

// copy constructor
Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain's copy constructor here" << std::endl;
}

// destructor
Brain::~Brain(void)
{
	std::cout << "Brain's destructor here" << std::endl;
}

// copy assignment operator overload
Brain&	Brain::operator=(const Brain& copy)
{
	std::cout << "Brain's copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	int length = sizeof(_ideas) / sizeof(_ideas[0]);
	for (int i = 0; i < length; i++)
		_ideas[i] = copy._ideas[i];
	return (*this);
}

// member functions
void Brain::setIdea(int index, std::string idea)
{
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return (_ideas[index]);
}
