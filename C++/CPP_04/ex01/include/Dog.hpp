/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:55:03 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 19:00:14 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& copy);
		Dog	&operator=(const Dog& copy);
		~Dog(void);
		void		makeSound() const;
		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);

	private:
		Brain* _brain;
};

#endif
