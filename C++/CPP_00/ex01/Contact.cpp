/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:31:58 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/01 16:31:19 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::set_first_name(std::string name)
{
	this->FirstName = name;
}

void	Contact::set_last_name(std::string name)
{
	this->LastName = name;
}

void	Contact::set_nickname(std::string name)
{
	this->Nickname = name;
}

void	Contact::set_phone_number(std::string number)
{
	this->PhoneNumber = number;
}

void	Contact::set_secret(std::string secret)
{
	this->DarkestSecret = secret;
}

std::string	Contact::get_first_name(void)
{
	return (this->FirstName);
}

std::string	Contact::get_last_name(void)
{
	return (this->LastName);
}

std::string	Contact::get_nickname(void)
{
	return (this->Nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->PhoneNumber);
}

std::string	Contact::get_secret(void)
{
	return (this->DarkestSecret);
}

