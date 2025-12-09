/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:06:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/08 13:20:34 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(): value(0) {
	std::cout << "Default construcor called" << std::endl;
	return ; 
}

Fixed::Fixed(const int n) {
	this->value = n << fractBit;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float f){
	this->value = roundf(f * (1 << fractBit)); 
	std::cout << "Float constructor called" << std::endl;
	return ; 
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return ; 
}

Fixed::Fixed(const Fixed &obj){
	std:: cout << "Copy constructor called" << std::endl;
	value = obj.value;
}

Fixed& Fixed::operator=(const Fixed &obj) {
	std:: cout << "Copy assignement operator called" << std::endl;
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

float Fixed::toFloat( void ) const{
	return (static_cast<float>(this->value) / (1 << fractBit));
}

int Fixed::toInt( void ) const{
	return(static_cast<int>(this->value) >> fractBit);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed){
	os << fixed.toFloat();
	return os;
}