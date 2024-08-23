/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/07 15:33:16 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	laura("laura");
	ClapTrap	amir("amir");

	amir.attack("laura");
	std::cout << "ClapTrap [amir] energy points: " << amir.getEnergyPoints() << std::endl;
	laura.takeDamage(amir.getAttackDamage());
	amir.setAttackDamage(4);
	amir.attack("laura");
	laura.takeDamage(amir.getAttackDamage());
	std::cout << "ClapTrap [laura] hit points: " << laura.getHitPoints() << std::endl;
	std::cout << "ClapTrap [amir] energy points: " << amir.getEnergyPoints() << std::endl;
	laura.beRepaired(4);
	std::cout << "ClapTrap [laura] hit points: " << laura.getHitPoints() << std::endl;
	std::cout << "ClapTrap [laura] energy points: " << laura.getEnergyPoints() << std::endl;
	amir.setAttackDamage(2);
	while (amir.getEnergyPoints() > 0 && laura.getHitPoints() > 0)
	{
		amir.attack("laura");
		laura.takeDamage(amir.getAttackDamage());
		std::cout << "ClapTrap [amir] energy points: " << amir.getEnergyPoints() << std::endl;
		std::cout << "ClapTrap [laura] hit points: " << laura.getHitPoints() << std::endl;
	}
	return (0);
}
