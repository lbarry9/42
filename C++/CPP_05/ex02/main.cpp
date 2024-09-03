/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:36:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 14:58:16 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "----------------------------------" << std::endl;
		Bureaucrat phil("Phil", 150);
		std::cout << "----------------------------------" << std::endl;
		ShrubberyCreationForm tree("Tree");
		phil.signForm(tree);
		phil.executeForm(tree);
		// RobotomyRequestForm robot("Rob");
		// phil.signForm(robot);
		// phil.executeForm(robot);
		// PresidentialPardonForm caf("Amir");
		// phil.signForm(caf);
		// phil.executeForm(caf);
		std::cout << "----------------------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	std::cout << "----------------------------------" << std::endl;
	return(0);
}
