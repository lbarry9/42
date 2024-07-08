/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:18:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/04 18:52:38 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(const std::string name, Weapon& input);
	~HumanA();
	void	attack();

	private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif

// &_weapon is a reference
// directly modify same memory address - weapon always already initalised
