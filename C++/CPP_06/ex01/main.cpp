/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:07:36 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/10 18:47:39 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	std::cout << "----------------------------------------------" << std::endl;
	Data data = {1, "Lynda"};
	std::cout << data.id << ", " << data.name << std::endl;
	Data *og_ptr = &data;
	std::cout << og_ptr << std::endl;
	std::cout << "----------------serialising pointer-----------" << std::endl;
	uintptr_t raw_int = Serializer::serialize(og_ptr);
	std::cout << raw_int << std::endl;
	std::cout << "---------------deserialising pointer----------" << std::endl;
	Data *new_ptr = Serializer::deserialize(raw_int);
	std::cout << new_ptr << std::endl;
	std::cout << new_ptr->id << ", " << new_ptr->name << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	if (new_ptr == og_ptr)
	{
		std::cout << "The deserialized pointer is equal to the original pointer." << std::endl;
	}
	else
	{
		std::cout << "The deserialized pointer is not equal to the original pointer." << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	return (0);
}
