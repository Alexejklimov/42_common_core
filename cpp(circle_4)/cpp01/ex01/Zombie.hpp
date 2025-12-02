/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:01:09 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/28 17:03:30 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#pragma once

class Zombie
{
	private:
		std::string name;

	public:
		void announce( void );
		void setName(std::string name);

		Zombie();
		~Zombie();
};

Zombie *zombieHorde( int n, std::string name );