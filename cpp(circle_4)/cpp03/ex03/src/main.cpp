/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:49:26 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:01:38 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main() {
    DiamondTrap stepan("Stepan");
    
    std::cout << std::endl;

    stepan.attack("enemy");
    stepan.beRepaired(42);
    stepan.takeDamage(400);
    stepan.guardGate();
    stepan.highFivesGuys();
    stepan.whoAmi();

    std::cout << std::endl;
    
    return 0;
}
