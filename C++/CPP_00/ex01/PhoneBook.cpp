/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:38:16 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/01 19:42:31 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "╔═════════════════════════════════════════╗" << std::endl;
	std::cout << "║     Welcome to my phonebook! ✏️📔✏️       ║" << std::endl;
	std::cout << "║   Type one of these commands to start:  ║" << std::endl;
	std::cout << "║                📝 ADD                   ║" << std::endl;
	std::cout << "║                🔍 SEARCH                ║" << std::endl;
	std::cout << "║                🚪 EXIT                  ║" << std::endl;
	std::cout << "╚═════════════════════════════════════════╝" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Ciao bella :)" << std::endl;
}

bool	PhoneBook::check_chars(std::string check)
{
	int	i = 0;
	while (check[i])
	{
		if (!isprint(check[i]) || !isalpha(check[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	PhoneBook::check_num(std::string check)
{
	int	i = 0;
	while (check[i])
	{
		if (!isprint(check[i]) || !isdigit(check[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	PhoneBook::check_index(std::string check)
{
	if (check.empty() || check.size() > 1)
		return (false);
	int i = 0;
	while (check[i])
	{
		if (!isdigit(check[i]))
			return (false);
		i++;
	}
	int num = check[0] - '0';
	if (num >= MAX_CONTACTS || num >= this->i || num < 0)
		return (false);
	return (true);
}

void	PhoneBook::add_contact(int i)
{
	int	j;
	if (i >= MAX_CONTACTS)
		j = 0;
	else
		j = i;
	std::string FirstName;
	while (!std::cin.eof())
	{
		std::cout << GREEN << "Enter contact's first name: " << RESET;
		if (std::getline(std::cin, FirstName))
			this->Contacts[j].set_first_name(FirstName);
		if ((FirstName.empty() || !check_chars(FirstName)) && !std::cin.eof())
			std::cout << RED << "Please enter valid characters" << RESET << std::endl;
		else if (!FirstName.empty())
			break;
	}
	std::string LastName;
	while (!std::cin.eof())
	{
		std::cout << GREEN << "Enter contact's last name: " RESET;
		if (std::getline(std::cin, LastName))
			this->Contacts[j].set_last_name(LastName);
		if ((LastName.empty() || !check_chars(LastName)) && !std::cin.eof())
			std::cout << RED << "Please enter valid characters" << RESET << std::endl;
		else if (!LastName.empty())
			break;
	}
	std::string Nickname;
	while (!std::cin.eof())
	{
		std::cout << GREEN << "Enter contact's nickname: " RESET;
		if (std::getline(std::cin, Nickname))
			this->Contacts[j].set_nickname(Nickname);
		if ((Nickname.empty() || !check_chars(Nickname)) && !std::cin.eof())
			std::cout << RED << "Please enter valid characters" << RESET << std::endl;
		else if (!Nickname.empty())
			break;
	}
	std::string Number;
	while (!std::cin.eof())
	{
		std::cout << GREEN << "Enter contact's phone number: " << RESET;
		if (std::getline(std::cin, Number))
			this->Contacts[j].set_phone_number(Number);
		if ((Number.empty() || !check_num(Number)) && !std::cin.eof())
			std::cout << RED << "Please enter valid characters" << RESET << std::endl;
		else if (!Number.empty())
			break;
	}
	std::string Secret;
	while (!std::cin.eof())
	{
		std::cout << GREEN << "Enter contact's darkest secret: " << RESET;
		if (std::getline(std::cin, Secret))
			this->Contacts[j].set_secret(Secret);
		if ((Secret.empty() || !check_chars(Secret)) && !std::cin.eof())
			std::cout << RED << "Please enter valid characters" << RESET << std::endl;
		else if (!Secret.empty())
			break;
	}
	this->i++;
}

void	PhoneBook::display_infos(int i)
{
	std::string	display;
	std::cout << "|";
	std::cout << std::setw(10) << (int)i;

	std::cout << "|";
	display = this->Contacts[i].get_first_name();
	if (display.size() > 10)
	{
		display.resize(9);
		display+= '.';
	}
	std::cout << std::setw(10) << display;

	std::cout << "|";
	display = this->Contacts[i].get_last_name();
	if (display.size() > 10)
	{
		display.resize(9);
		display+= '.';
	}
	std::cout << std::setw(10) << display;

	std::cout << "|";
	display = this->Contacts[i].get_nickname();
	if (display.size() > 10)
	{
		display.resize(9);
		display+= '.';
	}
	std::cout << std::setw(10) << display;
	std::cout << "|";
}

void	PhoneBook::search()
{
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	int	j = 0;
	int end = MAX_CONTACTS;
	if (this->i < MAX_CONTACTS)
		end = this->i;
	while (j < end)
	{
		this->display_infos(j);
		std::cout << std::endl;
		j++;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << std::endl;

	std::string index;
	int	i = 0;
	while(!std::cin.eof())
	{
		std::cout << GREEN << "Please choose contact index:" << RESET << std::endl;
		std::getline(std::cin, index);
		if (!check_index(index))
			std::cout << RED << "Please select a numeric index corresponding to one of the above contacts." << RESET << std::endl;
		else
		{
			i = index[0] - '0';
			break;
		}
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << "First Name: " << this->Contacts[i].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->Contacts[i].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->Contacts[i].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->Contacts[i].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->Contacts[i].get_secret() << std::endl;
	std::cout << "-------------------------" << std::endl;
}
