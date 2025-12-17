/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:49:26 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/10 19:48:31 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main() {
	ClapTrap a("Valera");
    ScavTrap b("Igor");

    std::cout << "\n   		Round 2\n   		Fight!!!" << std::endl;

    b.attack("Valera");
    b.guardGate();
    b.takeDamage(99);
    b.beRepaired(2);
    b.takeDamage(99);
    b.guardGate();

    std::cout << "\n	--- Finish him ---\n" << std::endl;

    return 0;
}