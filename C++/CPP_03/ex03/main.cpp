/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/07 21:28:11 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap Laura ("Laura");
	Laura.whoAmI();
	std::cout << "Hit points: " << Laura.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Laura.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Laura.getAttackDamage() << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	DiamondTrap Theresa;
	Theresa.whoAmI();
	Laura.attack("Theresa");
	Theresa.beRepaired(10);
	Theresa.highFivesGuys();
	Theresa.attack("Laura");
	Laura.guardGate();
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}
