/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:30:55 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/28 15:10:34 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

// orthodox canonical form member functions
Form::Form(void) : _name("Noname"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, const int sign, const int execute) : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(execute)
{
	std::cout << "Form Parametrised constructor called" << std::endl;
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(false), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
}

Form	&Form::operator=(const Form &copy)
{
	std::cout << "Form Copy assignement operator called" << std::endl;
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return (*this);
}

// getters / accessors
const	std::string Form::getName() const
{
	return (_name);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	Form::getSigned() const
{
	return (_isSigned);
}

// exception class .what() overrides
const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too high!!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too low!!");
}

// member fuction to sign form (called by Bureaucrat)
void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// non-member operator << overload
std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	o << "Form name: " << f.getName() << ", Grade needed to sign: " << f.getGradeToSign() << ", Grade needed to execute: " << f.getGradeToExecute() << ", Is form signed?: " << f.getSigned() << ".";
	return (o);
}
