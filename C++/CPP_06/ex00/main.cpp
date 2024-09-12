/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:07:36 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/09 18:49:39 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (!argv[1] || argc != 2)
	{
		std::cout << "Program requires one parameter" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}
