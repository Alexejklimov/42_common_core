/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:29:46 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/04 15:17:30 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::debug( void )
{
	std::cout << GREEN << "[ DEBUG ]"<< NORM << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << YELLOW << "[ INFO ]" << NORM << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << ORANGE << "[ WARNING ]" << NORM << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve"
		<< " been coming for years whereas you started working here since last month."
		 	<< std::endl;
}
void Harl::error( void )
{
	std::cout << RED << "[ ERROR ]"  << NORM << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." <<
		 std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*funcs[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << RED << "Unknown level of Harl`s Hysterics."
		" He probably evolved into Karen" << NORM << std::endl;
}
