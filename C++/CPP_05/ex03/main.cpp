/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:36:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 16:15:05 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/Intern.hpp"

int	main(void)
{
	try
	{
		std::cout << "----------------------------------" << std::endl;
		Bureaucrat phil("Phil", 1);
		std::cout << "----------------------------------" << std::endl;
		Intern dave;
		std::cout << "----------------------------------" << std::endl;
		AForm *yep = dave.makeForm("RobotomyRequestForm", "me");
		std::cout << "----------------------------------" << std::endl;
		std::cout << yep->getName() << std::endl;
		std::cout << "----------------------------------" << std::endl;
		phil.signForm(*yep);
		std::cout << "----------------------------------" << std::endl;
		phil.executeForm(*yep);
		std::cout << "----------------------------------" << std::endl;
		delete yep;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "----------------------------------" << std::endl;
	return(0);
}
