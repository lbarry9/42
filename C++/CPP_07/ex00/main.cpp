/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:19:18 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 18:17:51 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	std::string hey = "hey";
	std::string yo = "yo";

	std::cout << ::max(7, 3) << std::endl;
	std::cout << ::max('c', 'z') << std::endl;
	std::cout << ::max(0.0001, 7.5) << std::endl;
	std::cout << ::max(hey, yo) << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << ::min(7, 3) << std::endl;
	std::cout << ::min('c', 'z') << std::endl;
	std::cout << ::min(0.0001, 7.5) << std::endl;
	std::cout << ::min(hey, yo) << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << "before swapping :" << std::endl;
	std::cout << hey << ", " << yo << std::endl;
	swap(hey, yo);
	std::cout << "after swapping :" << std::endl;
	std::cout << hey << ", " << yo << std::endl;
	return(0);
}
