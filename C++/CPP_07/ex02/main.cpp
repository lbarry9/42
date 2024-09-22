/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:02:17 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/15 23:54:07 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "---------------Creating empty array--------------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	Array<int> hey;
	std::cout << "Array size: " << hey.size() << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "--------Creating array of specific size----------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	Array<int> hey2(4);
	std::cout << "Array size: " << hey2.size() << std::endl;
	for (size_t i = 0; i < 4; i++)
		hey2[i] = i;
	for (size_t i = 0; i < 4; i++)
		std::cout << hey2[i] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "------Creating array using copy constructor------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	Array<int> cpy(hey2);
	for (size_t i = 0; i < 4; i++)
		std::cout << cpy[i] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "---Accessing index 3 with [] operator overload---" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "hey 2 arr[3] = " << hey2[3] << std::endl;
	hey2[3] = 7;
	std::cout << "hey 2 after modifying arr[3] = " << hey2[3] << std::endl;
	std::cout << "this doesn't affect cpy arr[3] = " << cpy[3] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "--------Testing c0nst [] operator overload-------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	const Array<double> constArray(3);
	std::cout << constArray[0] << std::endl;
	//constArray[0] = 3;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "------------Testing array with strings-----------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (int i = 0; i < 3; i++)
		std::cout << strArray[i] << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "------------Testing out of bounds index----------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	try
	{
		std::cout << strArray[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------" << std::endl;
	return (0);
}
