/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:06:19 by marvin            #+#    #+#             */
/*   Updated: 2024/08/07 21:24:31 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

// default constructor
FragTrap::FragTrap(void) // find out why can't iniatialise here- have to use this
{
	this->_name = "Noname";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap [" << this->_name << "] initialised in default constructor" << std::endl;
}

// parametrised constructor
FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap [" << this->_name << "] initialised in parametrised constructor" << std::endl;
}

// copy constructor - initalises instance using parameter
// copy constructor of base class also explicitly called to avoid repeated logic
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap [" << this->_name << "] initialised in copy constructor" << std::endl;
}

// destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor" << std::endl;
}

// copy assignment operator overload - reassign meaning of = operator
FragTrap&	FragTrap::operator=(const FragTrap& copy)
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

// setters

void	FragTrap::setHitPoints()
{
	this->_hit_points = 100;
}

void	FragTrap::setEnergyPoints()
{
	this->_energy_points = 100;
}

void	FragTrap::setAttackDamage()
{
	this->_attack_damage = 30;
}

// member function unique to FragTrap
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap says give me a high five guys!" << std::endl;
}
