/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:05:03 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/04 14:15:01 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int	main(void)
{
	int		n = 1000;
	Zombie	*zombies = zombieHorde(n, "laura");

	for (int i = 0; i < n; i++)
		zombies[i].announce();

	delete[] zombies;

	return (0);
}
