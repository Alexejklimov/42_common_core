/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:49:26 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/11 08:58:07 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main() {
    FragTrap taras("Taras");
    FragTrap odarka("Odarka");
    std::cout << std::endl;

    taras.attack("enemy");
    taras.highFivesGuys();
    taras.takeDamage(99);
    taras.beRepaired(41);

    std::cout << std::endl;
    return 0;
}
