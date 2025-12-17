/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:33:47 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:22:09 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Default constructor called for Dog" << std::endl;
	type = "Dog";
}

Dog:: ~Dog()
{
	std::cout << "Destructor called for dog" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std:: cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) 
{
	std::cout << "Dog assigment constructor called" << std::endl;
	if (this != &obj)
	{
		Animal::operator=(obj);
	}
	return *this;
}


void Dog::makeSound() const 
{
	std::cout << "Гав, pardon - Woof" << std::endl;
}