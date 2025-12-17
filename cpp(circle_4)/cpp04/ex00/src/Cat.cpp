/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:33:42 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:21:11 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std:: cout << "Default Constructor called for Cat" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std:: cout << "Destructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat:: operator=( const Cat &obj)
{
	std:: cout<< "Cat assignement constructor called";
	if(this != &obj)
	{
		Animal::operator=(obj);
	}
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "Murrr miau" << std::endl;
}