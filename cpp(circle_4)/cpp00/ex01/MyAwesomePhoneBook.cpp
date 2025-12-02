/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:03:01 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/26 14:30:20 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhoneBook.hpp"


PhoneBook::PhoneBook(): contact_counter(0), book_size(0) {};

void Contact::setFirstName(const std::string &first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(const std::string &last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkSecret(const std::string &dark_secret) {
    this->dark_secret = dark_secret;
}

std::string Contact::getFirstName() { return first_name; }
std::string Contact::getLastName() { return last_name; }
std::string Contact::getNickName() { return nickname; }
std::string Contact::getPhoneNumber() { return phone_number; }
std::string Contact::getDarkSecret() { return dark_secret; }



void PhoneBook::addContact() {
	if (contact_counter >= 8) {
		contact_counter = 0;
		std::cout << RED <<"Phonebook is full. Replacing the oldest one"
					<< NORM << "\n\n";
	}
	Contact cont;
	std::string input;

	std::cout << "	Add new contact" << "\n\n";

	std::cout << "First name: ";
	if (!std::getline(std::cin, input)) {
		std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
		exit(1);
	}
	if (input.length() == 0) {
		while (input.length() == 0) {
			std::cout << RED << "no empty fields. Try harder" << NORM << '\n';
			std::cout << "First name: ";
			if (!std::getline(std::cin, input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
		}
	}
	cont.setFirstName(input);

	std::cout << "Last name: ";
	if (!std::getline(std::cin, input)) {
		std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
		exit(1);
	}
	if (input.length() == 0) {
		while (input.length() == 0) {
			std::cout << RED << "no empty fields. Try harder" << NORM << '\n';
			std::cout << "Last name: ";
			if (!std::getline(std::cin, input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
		}
	}
	cont.setLastName(input);

	std::cout << "Nickname: ";
	if (!std::getline(std::cin, input)) {
		std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
		exit(1);
	}
	if (input.length() == 0) {
		while (input.length() == 0) {
			std::cout << RED << "no empty fields. Try harder" << NORM << '\n';
			std::cout << "Nickname: ";
			if (!std::getline(std::cin, input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
		}
	}
	cont.setNickname(input);

	std::cout << "Phone number: ";
	if (!std::getline(std::cin, input)) {
		std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
		exit(1);
	}
	if (input.length() == 0 || !isNumber(input)) {
		while (input.length() == 0 || !isNumber(input)) {
			if (input.length() == 0) {
				std::cout << RED << "No empty fields. Try harder" << NORM << '\n';
			} else if (!isNumber(input)) {
				std::cout << RED << "Number means - it`s from digits. Try harder"
						<< NORM << '\n';
			}
			std::cout << "Phone number: ";
			if (!std::getline(std::cin, input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
		}
	}
	cont.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, input)) {
		std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
		exit(1);
	}
	if (input.length() == 0) {
		while (input.length() == 0) {
			std::cout << RED << "no empty fields. Try harder" << NORM << '\n';
			std::cout << "Darkest secret: ";
			if (!std::getline(std::cin, input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
		}
	}
	cont.setDarkSecret(input);

	contacts[contact_counter] = cont;
	contact_counter++;

	if (book_size < 8 )
		book_size++;
	std::cout << "	Contact added" << "\n\n";
}



void PhoneBook::searchContact() {
	if (contact_counter == 0) {
		std::cout << RED << "contact list is empty" << NORM << '\n';
		return;
	}

	std::cout << "	Contact list" << '\n';
	std::cout << std::setw(10) << "index" << '|'
				<< std::setw(10) << "First Name" << '|'
				<< std::setw(10) << "Last Name" << '|'
				<< std::setw(10) << "Nickname" << '|' << '\n';
	std::cout << "|---------|----------|----------|----------|" << '\n';

	for (int i = 0; i < book_size; i++) {
		std::cout << std::setw(10) << i << '|' 
				<< std::setw(10) << cutStr(contacts[i].getFirstName()) << '|'
				<< std::setw(10) << cutStr(contacts[i].getLastName()) << '|'
				<< std::setw(10) << cutStr(contacts[i].getNickName())
				<< '|' << "\n";
	}

	int search_index;
	std::string number_input;

	std::cout << "input index: ";
	if (!std::getline(std::cin, number_input)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}
	std::stringstream ss(number_input);

	if (!(ss >> search_index)) {
		std::cout << RED << "wrong input: numbers only"<< NORM << '\n';
	} else if (search_index < 0 || search_index >= book_size) {
		std::cout << RED << "wrong input: index is out of range" << NORM << '\n';
	} else {
		std::cout << '\n'
			<< "First name: " << contacts[search_index].getFirstName() << '\n'
			<< "Last name: "<< contacts[search_index].getLastName() << '\n'
			<< "Nickname: " << contacts[search_index].getNickName() << '\n'
			<< "Phone number: "<< contacts[search_index].getPhoneNumber() << '\n'
			<< "Darkest secret: " << contacts[search_index].getDarkSecret() << "\n\n";
	}
}


void PhoneBook::exitBook() {
	std::cout << "	bye" << std::endl;
	exit(0);
}

std::string PhoneBook::cutStr(const std::string &str) {
	if (str.length() > 10) {
		return str.substr(0,9).append(".");
	}
	return str;
}

bool PhoneBook::isNumber(const std::string &str) {
	if (str[0] != '+' && !isdigit(static_cast<unsigned char>(str[0]))) {
		return false;
	}
	if (str[0] == '+' && str.length() == 1) {
		return false;
	}
	for (size_t i = 1; i < str.length(); i++) {
		if (!isdigit(static_cast<unsigned char>(str[i]))) {
			return false;
		}
	}
	return true;
}