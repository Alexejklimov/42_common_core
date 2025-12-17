/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:16:45 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:21:03 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(): type("") {
	std::cout << "Default for Animal constructor called" << std::endl;
};

Animal:: ~Animal()
{
    std::cout << "Destructor for Animal called" << std::endl; 
    return ;
}

Animal::Animal( const Animal &obj)
{
	std:: cout << "Animal Copy constructor called" << std::endl;
    this->type = obj.type;
	return ;
}

Animal &Animal::operator=( const Animal &obj)
{
	std:: cout << "Animal Copy assignement Operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "I am an Animal." << std::endl;
}
