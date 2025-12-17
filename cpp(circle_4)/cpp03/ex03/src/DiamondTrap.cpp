/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:15:16 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 09:39:37 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), name("Default") {
    std::cout << "DiamondTrap " << this->name << " default constructor called"
		<< std::endl;
		
 	std::cout << std::endl;
	std::cout << "--> temporary constructors <--" << std::endl;
	std::cout << "<--                        -->" << std::endl;

	ScavTrap tmpST("tmp");
	FragTrap tmpFT("tmp");
	
	hp = tmpFT.getHp();
	e_points = tmpST.getEpoints();
	damage = tmpFT.getDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), name(name) {
		std::cout << "DiamondTrap " << this->name << " constructor called"
		<< std::endl;
		
		std::cout << std::endl;
		std::cout << "-->    tmp constructors    <--" << std::endl;
		ScavTrap tmpST("tmp");
		FragTrap tmpFT("tmp");

		hp = tmpFT.getHp();
		e_points = tmpST.getEpoints();
		damage = tmpFT.getDamage();

		std::cout << "-->    tmp destructors     <--" << std::endl;
	}


DiamondTrap::DiamondTrap(const DiamondTrap& obj)
    : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)   {
    std::cout << "DiamondTrap " << this->name << " copy constructor called."
		<< std::endl;
    *this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	if (this != &obj) {
		ClapTrap::operator=(obj);
		ScavTrap::operator=(obj);
		FragTrap::operator=(obj);
		name = obj.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructor called"
		<< std::endl;
}

void	DiamondTrap::whoAmi() {
	std::cout << "DiamondTrap name --> " << this->name << "\nClapTrap name    --> "
		<< ClapTrap::name << std::endl;
}
