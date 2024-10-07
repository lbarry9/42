/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:08:29 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/26 15:48:53 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::string		_input;
		int				_result;
		std::stack<int>	_stack;
	public:
		RPN(void);
		RPN(std::string input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
		void	rpn_calculator();
		void	format_check();
		int		getResult() const;
};

#endif
