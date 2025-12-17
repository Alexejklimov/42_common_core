/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:33:50 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:21:30 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal:: WrongAnimal() : type("WrongAnimal"){
    std::cout << "Default Constructor called for WrongAnimal" << std::endl;
}

WrongAnimal:: ~WrongAnimal()
{
    std::cout << "Destructor for WrongAnimal called" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
    this->type = obj.type;
	return;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &obj)
{
	std:: cout << "Animal Copy assignement Operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std:: cout << "i`m also an Animal, but something wrong in me." << std::endl; 
    return ;
}