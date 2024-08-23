/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:28:32 by marvin            #+#    #+#             */
/*   Updated: 2024/08/07 21:32:40 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	ClapTrap::_name = "Noname_clap_name";
	this->_name = "Noname";
	FragTrap::setHitPoints();
	ScavTrap::setEnergyPoints();
	FragTrap::setAttackDamage();
	std::cout << "DiamondTrap [" << this->_name << "] initialised in default constructor" << std::endl;
}

// parametrised constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	FragTrap::setHitPoints();
	ScavTrap::setEnergyPoints();
	FragTrap::setAttackDamage();
	std::cout << "DiamondTrap [" << this->_name << "] initialised in parametrised constructor" << std::endl;
}

// copy constructor - initalises instance using parameter
// copy constructor of base classes also explicitly called to avoid repeated logic
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap [" << this->_name << "] initialised in copy constructor" << std::endl;
}

// destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

// copy assignment operator overload - reassign meaning of = operator
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy)
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

// attack member function inherited from ScavTrap
void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

// unique member function
void	DiamondTrap::whoAmI(void)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "my name is [" << this->_name << "]!" << std::endl;
	std::cout << "my claptrap's name is [" << ClapTrap::getName() << "]" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}
