/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:47:18 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/22 17:17:44 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		~MutantStack() {}
		MutantStack	&operator=(MutantStack const &other)
		{
			this->c = other.c;
			return *this;
		}
		iterator	begin();
		iterator	end();
};

// typename definition ^ creates alias for iterator type
// container_type references underlying container of <stack> (deque by default)
// this->c.end() / this->c.begin() access iterators of underlying deque container
template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
