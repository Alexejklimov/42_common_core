/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:00:08 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 11:58:10 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " is destroyed." <<  std::endl;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string n) {
	this->name = n;
}