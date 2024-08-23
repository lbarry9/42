/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:23:06 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/07 16:50:12 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap(void): _name("Noname"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap [" << this->_name << "] initialised in default constructor" << std::endl;
}

// parametrised constructor
ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap [" << this->_name << "] initialised in parametrised constructor" << std::endl;
}

// copy constructor - initalises instance using parameter
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap [" << this->_name << "] initialised in copy constructor" << std::endl;
}

// destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap [" << this->_name << "] destroyed" << std::endl;
}

// copy assignment operator overload - reassign meaning of = operator
ClapTrap&	ClapTrap::operator=(const ClapTrap& copy)
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

/* ---------- getters ---------- */
std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

int	ClapTrap::getEnergyPoints(void)
{
	return(this->_energy_points);
}

int	ClapTrap::getHitPoints(void)
{
	return(this->_hit_points);
}

int	ClapTrap::getAttackDamage(void)
{
	return(this->_attack_damage);
}

/* ---------- setters ---------- */

void	ClapTrap::setAttackDamage(int damage)
{
	this->_attack_damage = damage;
}
/* --------member functions ------- */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap [" << this->_name << "] does not have enough energy points to attack :/" << std::endl;
		return ;
	}
	std::cout << "ClapTrap [" << this->_name << "] attacks [" << target << "] causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << "ClapTrap [" << this->_name << "] hit points reduced by " << amount << std::endl;
	if (this->_hit_points < 0)
		std::cout << "ClapTrap [" << this->_name << "] is dead..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap [" << this->_name << "] doesn't have enough energy points to repair themselves :(" << std::endl;
		return ;
	}
	this->_hit_points += amount;
	std::cout << "ClapTrap [" << this->_name << "] hit points repaired by " << amount << std::endl;
	this->_energy_points -= 1;
}
