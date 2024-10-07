/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:50:44 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/26 15:09:19 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<int, std::string>		_input;
		std::map<std::string, float>	_bitcoin;
		std::string						_date;
		float							_value;
		float							_result;
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::ifstream &file);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		void	check_and_calculate();
		int		check_dates(std::string line);
		int		check_format(std::string line);
		int		check_value(std::string line);
		void	calculate(std::map<int, std::string>::iterator &it);
		void	print_result();
		void	print_bitcoin();
};

#endif
