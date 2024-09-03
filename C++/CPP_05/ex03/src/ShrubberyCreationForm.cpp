/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:48:34 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 15:39:20 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Dunno yet")
{
	std::cout << "Shrubbery Form Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Form Parametrised constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
{
	std::cout << "Shrubbery Form Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cout << "Shrubbery Form Copy Assignation operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery Form Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file.is_open())
		throw FileErrorException();
	file << "                                                                 " << std::endl;
	file << "                                              .         ;        " << std::endl;
	file << "                 .              .              ;%     ;;         " << std::endl;
	file << "                   ,           ,                :;%  %;          " << std::endl;
	file << "                    :         ;                   :;%;'     .,   " << std::endl;
	file << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl;
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
	file << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
	file << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl;
	file << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl;
	file << "                        `@%.  `;@%.      ;@@%;                   " << std::endl;
	file << "                          `@%%. `@%%    ;@@%;                    " << std::endl;
	file << "                            ;@%. :@%%  %@@%;                     " << std::endl;
	file << "                              %@bd%%%bd%%:;                      " << std::endl;
	file << "                                #@%%%%%:;;                       " << std::endl;
	file << "                                %@@%%%::;                        " << std::endl;
	file << "                                %@@@%(o);  . '                   " << std::endl;
	file << "                                %@@@o%;:(.,'                     " << std::endl;
	file << "                            `.. %@@@o%::;                        " << std::endl;
	file << "                               `)@@@o%::;                        " << std::endl;
	file << "                                %@@(o)::;                        " << std::endl;
	file << "                               .%@@@@%::;                        " << std::endl;
	file << "                               ;%@@@@%::;.                       " << std::endl;
	file << "                              ;%@@@@%%:;;;.                      " << std::endl;
	file << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
	file.close();
	std::cout << "Check out the file: " << fileName << "!" << std::endl;
}
