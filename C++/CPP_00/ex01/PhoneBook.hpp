/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:54:56 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/01 19:36:02 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

# define MAX_CONTACTS 8
# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

class PhoneBook
{
	public:
	PhoneBook(void);
	~PhoneBook(void);
	int		i;
	void	add_contact(int i);
	void	search(void);

	private:
	Contact Contacts[8];
	void	display_infos(int i);
	bool	check_chars(std::string);
	bool	check_num(std::string);
	bool	check_index(std::string);
};

#endif
