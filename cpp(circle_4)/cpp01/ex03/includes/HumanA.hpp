/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:23:34 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:00:47 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

#include "Weapon.hpp"

#pragma once

class HumanA {
	private:
		Weapon& weapon;
		std::string name;

	public:
		void attack();
		
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
};