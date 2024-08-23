/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/07 16:53:28 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"

int	main(void)
{
	FragTrap Laura;
	FragTrap Theresa("Theresa");
	ClapTrap Denis ("Denis");
	Laura.attack("Theresa");
	Theresa.takeDamage(Laura.getAttackDamage());
	Theresa.beRepaired(10);
	Theresa.highFivesGuys();
	Denis.attack("Theresa");
	return (0);
}
