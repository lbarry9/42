/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:19:00 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/05 21:50:38 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(const std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& input);

	private:
	Weapon 		*_weapon;
	std::string	_name;
};

#endif

// *_weapon is a pointer to weapon class
// weapon type not always initalised so better to have a ptr
// which can be initalised to null- references must be initialised
