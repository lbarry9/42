/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:10:08 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 19:21:08 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &contnr, const int occur)
{
	typename T::iterator it = std::find(contnr.begin(), contnr.end(), occur);
	if (*it == occur)
		return (it);
	throw std::out_of_range("Value not found");
}

#endif
