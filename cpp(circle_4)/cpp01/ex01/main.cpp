/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:48 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 12:05:44 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int num  = 9;

	Zombie *zombieRush = zombieHorde(num, "Valera");
	
	for (int i = 0; i < num; i++) {
		zombieRush[i].announce();
	}
	
	delete[] zombieRush;
	zombieRush = NULL;

	return (0);
}