/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:49:26 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/10 17:26:04 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
	ClapTrap a("Valera");
    ClapTrap b("Igor");

    std::cout << "\n   		Round 1\n   		Fight!!!" << std::endl;

    a.attack("Igor");
    b.takeDamage(3);

    b.attack("Valera");
    a.takeDamage(5);

    b.beRepaired(4);
    a.beRepaired(2);

	b.attack("Valera");
    a.takeDamage(6);

    std::cout << "\n	--- Finish him ---\n" << std::endl;

    return 0;
}