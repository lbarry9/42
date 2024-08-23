/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/08 19:23:28 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int	main(void)
{
	const Animal* whoKnows = new Animal();
	std::cout << "Type is: "<< whoKnows->getType() << std::endl;
	whoKnows->makeSound();
	delete whoKnows;
	std::cout << "----------------------------------------" << std::endl;
	const Animal* Dave = new Dog();
	std::cout << "Type is: "<< Dave->getType() << std::endl;
	Dave->makeSound();
	delete Dave;
	std::cout << "----------------------------------------" << std::endl;
	const Animal* Bluebell = new Cat();
	std::cout << "Type is: "<< Bluebell->getType() << std::endl;
	Bluebell->makeSound();
	delete Bluebell;
	std::cout << "----------------------------------------" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << "Type is: "<< wrong->getType() << std::endl;
	wrong->makeSound();
	delete wrong;
	std::cout << "----------------------------------------" << std::endl;
	const WrongAnimal* Peanut = new WrongCat();
	std::cout << "Type is: "<< Peanut->getType() << std::endl;
	Peanut->makeSound();
	delete Peanut;
	// instantiable
	Animal Ron;
	return (0);
}
