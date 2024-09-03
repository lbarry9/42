/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:30:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/29 22:45:39 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

// orthodox canonical form member functions
AForm::AForm(void) : _name("Noname"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, const int sign, const int execute) : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(execute)
{
	std::cout << "AForm Parametrised constructor called" << std::endl;
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(false), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &copy)
{
	std::cout << "AForm Copy assignement operator called" << std::endl;
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return (*this);
}

// getters / accessors
const	std::string AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

// exception class .what() overrides
const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high!!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low!!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form has not yet been signed!");
}

const char *AForm::FileErrorException::what() const throw()
{
	return("File could not be opened...");
}

// member fuction to sign AForm (called by Bureaucrat)
void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// non-member operator << overload
std::ostream	&operator<<(std::ostream &o, const AForm &f)
{
	o << "AForm name: " << f.getName() << ", Grade needed to sign: " << f.getGradeToSign() << ", Grade needed to execute: " << f.getGradeToExecute() << ", Is form signed?: " << f.getIsSigned() << ".";
	return (o);
}
