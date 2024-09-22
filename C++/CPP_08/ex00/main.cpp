/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:34:13 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/22 17:33:35 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;
	for (int i = 0; i < 4; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}
	try
	{
		std::cout << *easyfind(vec, 3) << std::endl;
		std::cout << *easyfind(lst, 1) << std::endl;
		std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return (0);
}
