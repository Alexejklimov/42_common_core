/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:59:03 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/08 13:05:18 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return ; 
}

Fixed::Fixed(const Fixed &obj){
	std:: cout << "Copy constructor called" << std::endl;
	value = obj.value;
	return ;
}

Fixed& Fixed::operator=(const Fixed &obj){
	std:: cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		value = obj.value;
	return *this;
}

int Fixed::getRawBits( void ) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw; 
	return; 
}