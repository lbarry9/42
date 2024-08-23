/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:44:08 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 18:59:35 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <ostream>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);
		Brain&	operator=(const Brain& copy);
		std::string _ideas[100];
		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);
};

#endif
