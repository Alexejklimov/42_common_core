/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:29:20 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:31:52 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#pragma once

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();

		ScavTrap(std::string name);

		ScavTrap(const ScavTrap& obj);

		ScavTrap& operator=(const ScavTrap& obj);

		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};
