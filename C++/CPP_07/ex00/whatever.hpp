/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:33:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/16 18:18:07 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
T max(T x, T y)
{
	return(x > y) ? x : y;
}

template <typename U>
U min(U x, U y)
{
	return(x < y) ? x : y;
}

template <typename V>
void swap(V &x, V &y)
{
	V tmp = x;
	x = y;
	y = tmp;
}
