/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:51:20 by lbarry            #+#    #+#             */
/*   Updated: 2024/09/26 12:47:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	throw std::runtime_error("Error: could not open file.");
}

// stock input data in _input map
// stock bitcoin data in _bitcoin map
BitcoinExchange::BitcoinExchange(std::ifstream &infile)
{
	if (!infile.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (infile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: input file is empty.");
	std::string input_line;
	int i = 1;
	while (getline(infile, input_line))
	{
		_input.insert(std::pair<int, std::string>(i, input_line));
		i++;
	}
	infile.close();
	std::ifstream bitcoin ("docs/data.csv");
	if (!bitcoin.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (bitcoin.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: bitcoin database is empty.");
	std::string bit_line;
	while (getline(bitcoin, bit_line))
	{
		if (bit_line.size() < 12)
			throw std::runtime_error("Error: bad bitcoin database format.");
		_bitcoin.insert(std::pair<std::string, float>(bit_line.substr(0, 10), atof(bit_line.substr(11).c_str())));
	}
	bitcoin.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	_input = copy._input;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_input = copy._input;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::check_and_calculate()
{
	std::map<int, std::string>::iterator it = _input.begin();
	it++;
	while (it != _input.end())
	{
		if (check_dates(it->second))
		{
			_date = it->second.substr(0, 10);
			it->second.replace(0, it->second.size(), ("Error: bad input => " + _date));
		}
		else if (check_format(it->second))
		{
			std::string line = it->second.substr(0, it->second.size());
			it->second.replace(0, it->second.size(), "Error: bad input => " + line);
		}
		else if (check_value(it->second))
		{
			if (check_value(it->second) == -1)
				it->second.replace(0, it->second.size(), "Error: not a positive number.");
			else
				it->second.replace(0, it->second.size(), "Error: too large a number.");
		}
		else
			calculate(it);
		it++;
	}
}

void	BitcoinExchange::print_result()
{
	std::map<int, std::string>::iterator it = _input.begin();
	it++;
	while (it != _input.end())
	{
		std::cout << it->second << std::endl;
		it++;
	}
}

// 1. check valid date
int BitcoinExchange::check_dates(std::string line)
{
	int year = atoi(line.substr(0, 4).c_str());
	if (year < 2000 || year > 2024)
		return (1);
	int month = atoi(line.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return (1);
	int day = atoi(line.substr(8, 2).c_str());
	if (day < 1 || day > 31)
		return (1);
	if (month == 2)
	{
		if (year % 4 == 0 && day > 29)
			return (1);
		if (year % 4 != 0 && day > 28)
			return (1);
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (1);
	return (0);
}

// 2. line follows format 'date | value'
int	BitcoinExchange::check_format(std::string line)
{
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (1);
	if (line[4] != '-' || line[7] != '-')
		return (1);
	if (line.size() < 14)
		return (1);
	return (0);
}

// 3. value is valid int or float, positive, 0-1000
int	BitcoinExchange::check_value(std::string line)
{
	std::stringstream ss(line.substr(13));
	ss >> _value;
	if (_value < 0)
		return (-1);
	if (_value > 1000)
		return (1);
	return (0);
}

// compare _date (from input) to bitcoin map key it->first (date)
void	BitcoinExchange::calculate(std::map<int, std::string>::iterator &it)
{
	_date = it->second.substr(0, 10);
	std::map<std::string, float>::iterator bit_it = this->_bitcoin.lower_bound(_date);
	if (bit_it->first != _date)
		bit_it--;
	_result = bit_it->second * _value;
	it->second.replace(11, 1, "=>");
	std::stringstream ss;
	ss << _result;
	std::string result_str = ss.str();
	it->second.append(" = " + result_str);
}

void	BitcoinExchange::print_bitcoin()
{
	std::map<std::string, float>::iterator it = _bitcoin.begin();
	std::ofstream out("output.txt");
	if (!out.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (it != (--_bitcoin.end()))
	{
		out << it->first << "," << it->second << std::endl;
		it++;
	}
	out.close();
}
