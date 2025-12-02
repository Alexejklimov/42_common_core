/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:47:01 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/28 16:47:32 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zombilby = newZombie("Valera");
	zombilby->announce();
	delete zombilby;
	std::cout << std::endl;


	for (int i = 0; i < 10; i++) {
		std::ostringstream ss;
		ss << i;
		std::string name = "Zombie_" + ss.str();
		randomChump(name);
		std::cout << std::endl;
	}

	return (0);
}
