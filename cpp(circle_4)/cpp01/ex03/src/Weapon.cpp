/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:49:11 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:02:33 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string &type) {
	this->type = type;

	std::cout << "Constructor called for Weapon " << type << std::endl;
}

Weapon::~Weapon() {
	std::cout << type << " is destroyed " << std::endl;
}

const std::string Weapon::getType() {
	return (Weapon::type);
}

void Weapon::setType(std::string newType) {
	this->type = newType;
}