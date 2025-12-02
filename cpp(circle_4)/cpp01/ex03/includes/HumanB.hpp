/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:45:07 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:00:50 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon* weapon;
		std::string name;
	
	public:
		void setWeapon(Weapon& weapon);
		void attack();

		HumanB(std::string name);
		~HumanB();
};