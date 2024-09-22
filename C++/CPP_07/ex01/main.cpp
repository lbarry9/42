/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:40:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 18:29:08 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4};
	iter(arr, 5, print<int>);

	std::string arr2[] = {"Hello", "World", "it's", "me"};
	iter(arr2, 4, print<std::string>);
	return 0;
}
