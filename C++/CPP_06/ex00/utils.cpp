/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:40:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/09 19:49:20 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	check_int(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (input[i] == '.' || input[i] == 'f')
			i++;
		else if (!isdigit(input[i]))
			return (0);
	}
	return (1);
}

int	handle_pseudos(std::string const input)
{
	if (((!input.compare(0, 3, "nan", 0, 3) || !input.compare(0, 3, "inf", 0, 3)) && input.length() == 3) ||
	((!input.compare(0, 4, "nanf", 0, 4) || !input.compare(0, 4, "+inf", 0, 4)
	|| !input.compare(0, 4, "-inf", 0, 4)) && input.length() == 4) ||
	((!input.compare(0, 5, "+inff", 0, 5) || !input.compare(0, 5, "-inff", 0, 5)) && input.length() == 5))
	{
		int len = input.length();
		if (input == "nanf" || input.length() == 5)
			len = len -1;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input.substr(0, len) << "f" << std::endl;
		std::cout << "double: " << input.substr(0, len) << std::endl;
		return (1);
	}
	return (0);
}
