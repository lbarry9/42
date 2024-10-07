/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:08:27 by lbarry            #+#    #+#             */
/*   Updated: 2024/10/02 17:35:36 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	throw std::invalid_argument("Error: please provide an argument");
}

RPN::RPN(std::string input) : _input(input), _result(0) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		_input = copy._input;
		_result = copy._result;
		_stack = copy._stack;
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::rpn_calculator()
{
	format_check();
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (isdigit(*it))
		{
			int num = 0;
			while (isdigit(*it))
			{
				num = num * 10 + *it - '0';
				it++;
			}
			_stack.push(num);
		}
		else
		{
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();

			if (*it == '+')
				_stack.push(b + a);
			else if (*it == '-')
				_stack.push(b - a);
			else if (*it == '*')
				_stack.push(b * a);
			else if (*it == '/')
			{
				if (a == 0)
					throw std::invalid_argument("Error: Division by zero");
				_stack.push(b / a);
			}
		}
	}
	_result = _stack.top();
}

// separate error checks with maths format checks
// error checks - char by char
// maths format checks - go up tp space and stock the number corrctly then check num count
void	RPN::format_check()
{
	int op_count = 0;
	int num_count = 0;
	for (std::string::iterator it = _input.begin(); it != _input.end(); it++)
	{
		if (*it == '\0')
			break;
		if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			throw std::invalid_argument("Error: invalid input");
		if (isdigit(*it) && (*it < '0' || *it > '9'))
			throw std::invalid_argument("Error: invalid input");
		if (*it == '(' || *it == ')' || *it == '.')
			throw std::invalid_argument("Error: invalid input");
		if (isdigit(*it))
		{
			while (isdigit(*it))
				it++;
			num_count++;
			if (*it != ' ')
				throw std::invalid_argument("Error: invalid input");
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (op_count == 0 && num_count < 2)
				throw std::invalid_argument("Error: invalid input");
			op_count++;
			*it++;
		}
		if (*it == ' ')
			continue;
		if (op_count == 1 && num_count != 2)
			throw std::invalid_argument("Error: invalid input");
		if (op_count > 1 && num_count != op_count + 1)
			throw std::invalid_argument("Error: invalid input");
	}
	if (op_count != num_count - 1)
		throw std::invalid_argument("Error: invalid input");
}

int	RPN::getResult() const
{
	return (_result);
}
