/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:56:32 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/21 21:37:56 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>

class	Span
{
	private:
		std::vector<int>	_nums;
		unsigned int		_N;

	public:
		Span(void);
		Span(unsigned int maxNum);
		Span(Span const &other);
		~Span(void);
		Span	&operator=(Span const &other);
		void	addNumber(int nbr);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
		class AlreadyFull : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return "Container already full";
			}
		};
		class NotEnoughSpace : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return "Not enough space";
			}
		};
		class SpanNotPossible : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return "Not possible to calculate span";
			}
		};
};

#endif
