/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:33:52 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:32:57 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#pragma once

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
	
		FragTrap(std::string name);

		FragTrap(const FragTrap& obj);

		FragTrap& operator=(const FragTrap& obj);

		~FragTrap();

		void	highFivesGuys(void);

		unsigned int getHp();
		unsigned int getDamage();
};
