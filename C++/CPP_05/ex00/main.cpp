/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:36:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/28 14:38:03 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bab("Laura", 99);
		std::cout << bab.getName() << " " << bab.getGrade() << std::endl;
		std::cout << "incrementing grade --> ";
		bab.incrementGrade();
		std::cout << bab.getGrade() << std::endl;
		std::cout << "decrementing grade --> ";
		bab.decrementGrade();
		std::cout << bab.getGrade() << std::endl;
		std::cout << bab << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		std::cout << "----------------------------------" << std::endl;
		Bureaucrat bil("Bilou", 0);
		std::cout << bil.getName() << " " << bil.getGrade() << std::endl;
		bil.incrementGrade();
		std::cout << bil.getGrade() << std::endl;
		bil.decrementGrade();
		std::cout << bil.getGrade() << std::endl;
		std::cout << bil << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		std::cout << "----------------------------------" << std::endl;
		Bureaucrat ah("Ahlem", 151);
		std::cout << ah.getName() << " " << ah.getGrade() << std::endl;
		ah.incrementGrade();
		std::cout << ah.getGrade() << std::endl;
		ah.decrementGrade();
		std::cout << ah.getGrade() << std::endl;
		std::cout << ah << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "----------------------------------" << std::endl;
	return(0);
}
