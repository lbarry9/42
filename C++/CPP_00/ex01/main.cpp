/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:16:38 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/01 19:30:15 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook 	MyPhoneBook;
	std::string	input;

	MyPhoneBook.i = 0;
	while (1 && !std::cin.eof())
	{
		std::cout << GREEN << "Please enter a command:" << RESET << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			MyPhoneBook.add_contact(MyPhoneBook.i);
		else if (input == "SEARCH")
			MyPhoneBook.search();
		else if (input == "EXIT")
			return (0);
		else if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		else
			std::cout << RED << "Invalid command. Please choose one of the following options: ADD, SEARCH or EXIT." << RESET << std::endl;
	}
	return (0);
}
