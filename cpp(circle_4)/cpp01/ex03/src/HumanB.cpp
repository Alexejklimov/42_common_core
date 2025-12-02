/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:56:18 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:03:21 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;

	std::cout << "Constructor called for HumanB " << name << std::endl; 
}

HumanB::~HumanB() {
	std::cout << "HumanB " << this->name << " is destroyed" <<  std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon) {
			std::cout << this->name << " attacks with their "
				<< this->weapon->getType() << std::endl;
	} else {
		std::cout << this->name << " has no weapon" << std::endl;
	}
}