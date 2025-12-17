/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:34:29 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 09:43:50 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultValera") {
	std::cout << "FragTrap " << this->name << " default constructor called"
		<< std::endl;
	hp = 100;
	e_points = 100;
	damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << this->name << " default constructor called"
		<< std::endl;
	hp = 100;
	e_points = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "FragTrap " << obj.name << " copy constuctor called."
		<< std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &obj) {
		this->name = obj.name;
		this->hp = obj.hp;
		this->e_points = obj.e_points;
		this->damage = obj.damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	    std::cout << "FragTrap " << this->name << " destructor called"
			<< std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " displays a positive high-fives request"
		<< std::endl;
}