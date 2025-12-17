/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:20:46 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:21:43 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std:: cout << "Default Constructor called for WrongCat" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "Destructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& obj) {
	std::cout << "WrongCat assigment constructor" << std::endl;
	if (this != &obj) {
		WrongAnimal::operator=(obj);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "mouuu" << std::endl;
}