/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:51:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/26 12:52:41 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhoneBook.hpp"

int main() {
	PhoneBook book;
	std::string input_command;

	while (true) {
		std::cout << "input command: ";
		if (!std::getline(std::cin, input_command)) {
				std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
				exit(1);
			}

		if (input_command == "ADD") {
			while (true) {
				std::string add_option;
				book.addContact();
				std::cout << " want to add another contact"
							<< "- press ENTER. Want to exit - type NO" << '\n';
				if (std::getline(std::cin, add_option)) {
					if (add_option == "NO") {
						std::cout << '\n';
						break;
					}
				} else {
					std::cout << RED << '\n' << "sometimes getline() - sucks." << '\n';
					exit(1);
				}
			}
		}
		else if (input_command == "SEARCH") {
			book.searchContact();
		}
		else if (input_command == "EXIT") {
			book.exitBook();
		}
		else {
			std::cout << RED << "ADD, SEARCH or EXIT. Nothing else doesn`t work" << NORM << '\n';
		}
	}
	return (0);
}
