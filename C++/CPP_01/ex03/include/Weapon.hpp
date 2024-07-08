/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:54:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/04 18:49:45 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <ostream>
#include <iostream>

class Weapon
{
	public:
	Weapon(void);
	Weapon(std::string weapon);
	~Weapon(void);
	const std::string&	getType(void) const;
	void				setType(const std::string newType);

	private:
	std::string	type;
};

#endif
