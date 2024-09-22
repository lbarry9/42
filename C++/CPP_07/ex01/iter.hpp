/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:41:24 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 18:28:14 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
#define	ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T, typename F>

void	iter(T &arr, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
