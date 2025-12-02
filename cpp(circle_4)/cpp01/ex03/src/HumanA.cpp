/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:48:53 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:03:15 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
	std::cout << "Constructor called for HumanA " << name << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA " << this->name << " is destroyed" <<  std::endl;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType()
		<< std::endl;
}


