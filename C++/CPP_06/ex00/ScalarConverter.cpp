/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:18:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/09 20:12:48 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// orthodox canonical form functions
ScalarConverter::ScalarConverter(void) {};

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {};

// convert function required:
// 1. detect variable type, 2. convert it from string to actual type
// 3. convert explicitly to all (other) data types
void	ScalarConverter::convert(std::string const input)
{
	if (handle_pseudos(input))
		return ;
	std::cout << "char: ";
	long tmp = std::strtol(input.c_str(), NULL, 10);
	if ((input.length() != 1 && !check_int(input)) || tmp <= std::numeric_limits<char>::min()
		|| tmp >= std::numeric_limits<char>::max() || (!isprint(tmp) && !std::isalpha(input[0])))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else if (check_int(input))
		std::cout << "'" << static_cast<char>(tmp) << "'" << std::endl;
	else
		std::cout << "'" << input[0] << "'" << std::endl;
	std::cout << "int: ";
	if (tmp <= LONG_MIN || tmp >= LONG_MAX)
		std::cout << "Non displayable" << std::endl;
	else if (std::isalpha(input[0]) && input.length() == 1)
		std::cout << static_cast<int>(input[0]) << std::endl;
	else if (!check_int(input))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<int>(std::strtol(input.c_str(), NULL, 10)) << std::endl;
	std::cout << "float: " << static_cast<float>(std::strtof(input.c_str(), NULL)) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(std::strtof(input.c_str(), NULL)) << ".0" << std::endl;
}
