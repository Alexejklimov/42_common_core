/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:50:02 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/28 16:04:04 by oklimov          ###   ########.fr       */
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

	Zombie(std::string name);
	~Zombie();
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

