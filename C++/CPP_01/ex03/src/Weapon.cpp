/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:01:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/04 19:00:17 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string Weapon)
{
	this->type = Weapon;
	//std::cout << "Creating Weapon instance with: " << Weapon << std::endl;
}

Weapon::Weapon(void)
{
	this->type = "bare hands (no weapon)";
	//std::cout << "Creating Weapon instance with: " << this->type << std::endl;
}

Weapon::~Weapon(void){}

const std::string&	Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
	//std::cout << "Replacing weapon with: " << newType << std::endl;
}
