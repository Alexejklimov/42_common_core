/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:36:07 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 13:11:09 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor for Brain" << std::endl;
};

Brain:: ~Brain() {
	std::cout << "Default constructor for Brain" << std::endl;
}

Brain::Brain(const Brain& obj) {
std:: cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) 
		this->ideas[i] = obj.ideas[i];
	return ;
}

Brain &Brain::operator=(const Brain& obj) {
	std:: cout << "Brain Copy assignement Operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

