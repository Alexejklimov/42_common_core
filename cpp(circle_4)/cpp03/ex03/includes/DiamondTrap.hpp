/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:14:56 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:10:30 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#pragma once

class DiamondTrap : public ScavTrap, public FragTrap  {
	private:
		std::string name;
	public:
		DiamondTrap();

		DiamondTrap(std::string name);

		DiamondTrap(const DiamondTrap& obj);

		DiamondTrap& operator=(const DiamondTrap& obj);

		~DiamondTrap();

		void whoAmi();
};
