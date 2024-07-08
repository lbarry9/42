/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:02:05 by marvin            #+#    #+#             */
/*   Updated: 2024/07/04 14:12:20 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <ostream>

class Zombie
{
	public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
	void	announce(void);

	private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
