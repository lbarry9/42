/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:56:40 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/22 18:06:06 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int maxNum) : _N(maxNum)
{
	std::cout << "Span parametrised constructor called" << std::endl;
}

Span::Span(Span const &copy) : _N(copy._N)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span	&Span::operator=(Span const &copy)
{
	if (this == &copy)
		return (*this);
	_N = copy._N;
	_nums = copy._nums;
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
}

void	Span::addNumber(int num)
{
	if (_nums.size() >= _N)
		throw AlreadyFull();
	_nums.push_back(num);
	//std::cout << "adding : " << num << std::endl;
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_nums.size() + std::distance(begin, end) > _N)
		throw NotEnoughSpace();
	_nums.insert(_nums.end(), begin, end);
	//std::cout << "adding numbers between: " << *begin << " - " << *(end -1) << std::endl;
}


int	Span::longestSpan()
{
	if (_nums.size() < 2)
		throw SpanNotPossible();
	std::vector<int>::iterator max = std::max_element(_nums.begin(), _nums.end());
	std::vector<int>::iterator min = std::min_element(_nums.begin(), _nums.end());
	int	span = std::abs(*min - *max);
	return (span);
}

int	Span::shortestSpan()
{
	if (_nums.size() < 2)
		throw SpanNotPossible();
	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());
	int span = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size(); i++)
		span = std::min(span, std::abs(sorted[i] - sorted[i - 1]));
	return (span);
}
