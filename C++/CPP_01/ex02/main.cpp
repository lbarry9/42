/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:41:38 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/05 21:43:30 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ostream>
#include <iostream>

int	main(void)
{
	std::string hi = "HI THIS IS BRAIN";
	std::string *stringPTR = &hi;
	std::string &stringREF = hi;

	std::cout << "Memory address of original string : " << &hi << std::endl;
	std::cout << "Memory address stored in stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address stored in stringREF: " << &stringREF << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Value of original string     : " << hi << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	// std::cout << "---------------------------------------------------" << std::endl;
	// std::cout << "Memory address of string   : " << &hi << std::endl;
	// std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	// std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	return (0);
}
