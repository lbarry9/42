/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:08:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 16:12:46 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern	&Intern::operator=(Intern const &copy)
{
	std::cout << "Intern Dopy assignation operator called" << std::endl;
	if (this != &copy)
	{
		(void)copy;
	}
	return (*this);
}

AForm	*Intern::makePresidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(Intern::*formFuncs[3])(std::string target) = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formFuncs[i])(target);
		}
	}
	throw AForm::FormNotFoundException();
}
