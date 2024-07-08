/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:57:08 by marvin            #+#    #+#             */
/*   Updated: 2024/07/04 13:42:58 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

// No name Laura and Bob all on the stack, Amir on the heap (new)

int	main(void)
{
	Zombie noNameZombie;
	Zombie lauraZombie("Laura");

	noNameZombie.announce();
	lauraZombie.announce();

	Zombie *amirZombie;
	amirZombie = newZombie("Amir");
	amirZombie->announce();

	randomChump("Bob");

	delete amirZombie;

	return (0);
}
