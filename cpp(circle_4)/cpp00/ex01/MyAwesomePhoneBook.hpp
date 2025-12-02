/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:03:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/26 13:36:05 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <sstream>

#define RED     "\033[31m"
#define NORM   "\033[0m"

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;
		
	public:
		void setFirstName(const std::string	&first_name);
		void setLastName(const std::string	&last_name);
		void setNickname(const std::string	&nickname);
		void setPhoneNumber(const std::string	&phone_number);
		void setDarkSecret(const std::string	&dark_secret);

		std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getDarkSecret();
        std::string getPhoneNumber();
};

class PhoneBook {
	private:
		int	contact_counter;
		int book_size;
		Contact	contacts[8];

	public:
		PhoneBook();
		void addContact();
		void searchContact();
		void exitBook();

	private:
		static std::string cutStr(const std:: string &str);
		static bool isNumber(const std::string &str);
	
};
