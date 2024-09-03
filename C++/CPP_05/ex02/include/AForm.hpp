/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:32:47 by lbarry            #+#    #+#             */
/*   Updated: 2024/08/29 22:46:36 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, const int sign, const int execute);
		AForm(const AForm &copy);
		~AForm(void);
		AForm				&operator=(const AForm &copy);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &b);
		virtual void		execute(Bureaucrat const &executor) const = 0;

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	FormNotSignedException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	FileErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif
