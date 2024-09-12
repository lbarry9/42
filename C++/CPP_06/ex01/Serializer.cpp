/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:13:16 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/09 22:23:45 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// orthodox canonical form functions
Serializer::Serializer(void) {};

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer	&Serializer::operator=(const Serializer &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

Serializer::~Serializer(void) {};

// member functions
uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
