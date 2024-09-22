/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:56:56 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/21 23:41:51 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::cout << "----------------- testing subject main -----------------" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(2);
		std::cout  << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------- testing addNumber (iterators) ------------" << std::endl;
	std::srand(time(NULL));
	std::vector<int> big(10000);
	for (int i = 0; i < 10000; ++i)
		big[i] = std::rand();
	try
	{
		Span woo(10000);
		woo.addNumber(big.begin(), big.end());
		std::cout << "shortest span: " << woo.shortestSpan() << std::endl;
		std::cout << "longest span : " << woo.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
