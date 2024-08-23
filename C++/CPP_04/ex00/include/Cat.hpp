/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:27:31 by marvin            #+#    #+#             */
/*   Updated: 2024/08/02 12:27:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& copy);
		Cat	&operator=(const Cat& copy);
		~Cat(void);
		void	makeSound() const;
};

#endif
