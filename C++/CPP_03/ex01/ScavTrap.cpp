/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:39:16 by marvin            #+#    #+#             */
/*   Updated: 2024/08/07 16:50:21 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(void)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap [" << this->_name << "] initialised in default constructor" << std::endl;
	std::cout << "Hit points: " << this->_hit_points << std::endl;
	std::cout << "Energy points: " << this->_energy_points << std::endl;
	std::cout << "Attack damage: " << this->_attack_damage << std::endl;
}

// parametrised constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap [" << this->_name << "] initialised in parametrised constructor" << std::endl;
	std::cout << "Hit points: " << this->_hit_points << std::endl;
	std::cout << "Energy points: " << this->_energy_points << std::endl;
	std::cout << "Attack damage: " << this->_attack_damage << std::endl;
}

// copy constructor - initalises instance using parameter
// copy constructor of base class also explicitly called to avoid repeated logic
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap [" << this->_name << "] initialised in copy constructor" << std::endl;
}

// destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap [" << this->_name << "] destroyed" << std::endl;
}

// copy assignment operator overload - reassign meaning of = operator
ScavTrap&	ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_attack_damage = copy._attack_damage;
	this->_energy_points = copy._energy_points;
	this->_hit_points = copy._hit_points;
	return (*this);
}

// attack member function with personalised message
void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ScavTrap [" << this->_name << "] does not have enough energy points to attack :/" << std::endl;
		return ;
	}
	std::cout << "ScavTrap [" << this->_name << "] attacks [" << target << "] causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

// member function unique to ScapTrap
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap [" << this->_name << "] is now in Gate Keeper Mode" << std::endl;
}
