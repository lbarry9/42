/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:51:11 by lbarry            #+#    #+#             */
/*   Updated: 2024/06/28 23:46:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "PhoneBook.hpp"

class Contact
{
	public:
	Contact(void);
	~Contact(void);
	void		set_first_name(std::string);
	void		set_last_name(std::string);
	void		set_nickname(std::string);
	void		set_phone_number(std::string);
	void		set_secret(std::string);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone_number(void);
	std::string	get_secret(void);

	private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string PhoneNumber;
	std::string	DarkestSecret;
};

#endif
