/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:14:56 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/05 22:38:33 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class	Harl
{
	public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);

	private:
	std::string	_level[4];
	void		(Harl::*_func[4])();
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
};

#endif
