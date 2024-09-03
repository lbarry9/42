/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:44:12 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/30 14:54:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

// orthodox canonical form member functions
Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(0)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Parametrised constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Copy assignement operator called" << std::endl;
	if (this != &copy)
		_grade = copy._grade;
	return (*this);
}

// getters
const	std::string Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

// incrementers
void	Bureaucrat::incrementGrade()
{
	if (_grade -1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

// exception class .what() overrides
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low!!");
}

// member function which tries to sign form
void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << *this << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// member function which tries to execute form
void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->getName() << " executed form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << " could not execute form " << form.getName() << " because " << e.what() << '\n';
	}
}

// non-member operator << overload
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
