/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:10:53 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 15:13:39 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#pragma once

class Dog: public Animal {
	public:
		Dog(); 

        ~Dog(); 

        Dog( const Dog &obj);

        Dog &operator=( const Dog &obj);

		void makeSound() const ;
};