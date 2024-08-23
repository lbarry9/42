/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:13:01 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/08 19:12:36 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"

int	main(void)
{
	int		n = 6;
	Animal*	array[n];

	std::cout << "------------- Creating dogs who bark ------------" << std::endl;
	for (int i = 0; i < n / 2; i++)
	{
		array[i] = new Dog();
		array[i]->makeSound();
	}
	std::cout << "------------- Creating cats who meow ------------" << std::endl;
	for (int i = n / 2; i < n; i++)
	{
		array[i] = new Cat();
		array[i]->makeSound();
	}
	std::cout << "------------- Deleting array of Animals ----------" << std::endl;
	for (int i = 0; i < n; i++)
		delete array[i];

	std::cout << "------- Testing for deep copy using copy constuctor (no double frees) -------" << std::endl;
	Dog fred("Fred");
	// set ideas
	fred.setIdea(0, "<< Let's go play! >>");
	std::cout << fred.getIdea(0) << std::endl;
	Dog tmp = fred;
	// get ideas of both
	std::cout << tmp.getIdea(0) << std::endl;
	// new give ideas
	tmp.setIdea(0, "<< I wana eat first... >>");
	std::cout << "Tmps new idea : " << tmp.getIdea(0) << std::endl;
	std::cout << "Fred's idea : "<< fred.getIdea(0) << std::endl;

	// // Cat hey;
	// // Cat hey2 = hey;
	std::cout << "------- Animal class is now abstract -------" << std::endl;
	Animal	Bob;
	return (0);
}
