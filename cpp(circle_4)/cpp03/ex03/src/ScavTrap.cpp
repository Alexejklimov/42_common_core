/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:29:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:11:40 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav") {
std::cout << "ScavTrap " << this->name << " default constructor called"
		<< std::endl;

    hp = 100;
    e_points = 50;
    damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << this->name << " constructor called"
		<< std::endl;
	hp = 100;
	e_points = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << "ScavTrap " << obj.name << " copy constuctor called."
		<< std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &obj) {
		this->name = obj.name;
		this->hp = obj.hp;
		this->e_points = obj.e_points;
		this->damage = obj.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	    std::cout << "ScavTrap " << this->name << " destructor called"
			<< std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (e_points <= 0) {
		std::cout << "ScavTrap " << name << " Sorry, but 'No energy - no attack'"
			<< std::endl;
		return;
	} else if (hp <= 0) {
		std::cout << "ScavTrap " << name << " Definetely cannot attack. He is dead"
			<< std::endl;
		return;
	}

	std::cout << "ScavTrap " << name << " punch " << target << " that delivers "
		<< damage << " points of damage!" << std::endl;
	e_points--;
}


void	ScavTrap::guardGate() {
	if (hp == 0) {
		std::cout << "A dead ScavTrap "<< this->name << " lies by the Gate."
			<< " It doesn`t look like a guard" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is now in a Gate keeper mode!"
			<< std::endl;
}

unsigned int ScavTrap::getEpoints() {
	return this->e_points;
}