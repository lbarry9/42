/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:08:59 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 16:11:04 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Aform;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern	&operator=(const Intern &copy);
		AForm	*makeForm(const std::string name, const std::string target);

	private:
		AForm	*makePresidentialForm(const std::string target);
		AForm	*makeRobotomyForm(const std::string target);
		AForm	*makeShrubberyForm(const std::string target);
};

#endif
