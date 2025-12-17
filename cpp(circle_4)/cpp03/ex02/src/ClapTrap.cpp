/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:49:17 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 09:37:26 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

//--- OCF ---//

ClapTrap::ClapTrap():  name("Valera"), hp(10), e_points(10), damage(0) {
	std::cout << "ClapTrap " << this->name << " Default constructor called" << std::endl;

}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), e_points(10), damage(0) {
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std:: cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	if (this != &obj) {
		this->name = obj.name;
		this->hp = obj.hp;
		this->e_points = obj.e_points;
		this->damage = obj.damage;
	}
	return *this;
}


//--- Methods ---//


void	ClapTrap::attack(const std::string& target) {
	if (e_points <= 0) {
		std::cout << "ClapTrap " << name << "Not enough energy points to attack :("
			<< std::endl;
		return;
	} else if (hp <= 0) {
		std::cout << "ClapTrap " << name << "Not enough hit points to attack :("
			<< std::endl;
		return;
	}

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< damage << " points of damage!" << std::endl;
	e_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ((int)amount < 0) {
		std::cout << "Negative damage is not allowed! did you just hit yourself?"
			<< std::endl;
		return;
	}
	if (hp == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed. You can`t kill him twice."
			<< std::endl;
		return;
	}
	if (amount >= hp) {
		hp = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " damage. He`s destroyed"
			<< std::endl;
	} else {
		hp -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " damage. HP = "
			<< hp << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if ((int)amount < 0) {
		std::cout << "Cannot repair with negative value. Self-medication can be harmful"
			<< std::endl;
		return;
	}
	if (hp == 0) {
		std::cout << "ClapTrap " << name << " is already destroyed. We don`t use necromancy here"
			<< std::endl;
		return;
	}
	if (e_points == 0) {
		std::cout << "ClapTrap " << name << " has no energy points left."
			<< std::endl;
		return;
	}
		hp += amount;
		e_points--;
		std::cout << "ClapTrap " << name << " repair itself for " << amount << " points. HP = "
			<< hp << std::endl;
}
