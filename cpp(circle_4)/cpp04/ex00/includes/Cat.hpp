/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:57:35 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 15:13:36 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#pragma once

class Cat: public Animal {
	public:
		Cat(); 

        ~Cat(); 

        Cat( const Cat &obj);

        Cat &operator=( const Cat &obj);

		void makeSound() const ;
};