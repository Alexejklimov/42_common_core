/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:35:36 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/10 17:28:02 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		unsigned int	hp;
		unsigned int	e_points;
		unsigned int	damage;

	public:
		ClapTrap();

		ClapTrap(std::string name);

		ClapTrap(const ClapTrap& obj);
		
		~ClapTrap();
		
		ClapTrap &operator=(const ClapTrap &obj );
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
