/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:57:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 11:57:04 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde (int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie *unit = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::ostringstream ss;
		ss << i;
		if (i >= 1 && name.length() >= 2) {
			name.erase(name.size() - 2);
		}
		name = name + "_" + ss.str();
		unit[i].setName(name);
	}
	return (unit);
}