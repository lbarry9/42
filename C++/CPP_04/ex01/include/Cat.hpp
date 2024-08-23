/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:27:31 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 19:00:18 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& copy);
		Cat	&operator=(const Cat& copy);
		~Cat(void);
		void		makeSound() const;
		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);

	private:
		Brain* _brain;
};

#endif
