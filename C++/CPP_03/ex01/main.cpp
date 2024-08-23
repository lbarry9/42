/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/07 16:43:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap Laura;
	ScavTrap Theresa("Theresa");
	ClapTrap Alex ("Alex");
	Alex.attack("Theresa");
	Theresa.takeDamage(Alex.getAttackDamage());
	Theresa.beRepaired(10);
	Theresa.guardGate();
	Theresa.attack("Alex");
	return (0);
}
