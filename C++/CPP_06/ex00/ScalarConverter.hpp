/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:18:13 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/09 22:29:14 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <limits.h>
#include <exception>
#include <typeinfo>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter	&operator=(const ScalarConverter &copy);
		~ScalarConverter(void);

	public:
		static void	convert(std::string const input);
};

int	check_int(std::string input);
int	handle_pseudos(std::string const input);

#endif
