/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:57:35 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 13:12:43 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#pragma once

class Cat: public Animal {
	private:
		Brain* brain;
	public:
		Cat(); 

        ~Cat(); 

        Cat( const Cat &obj);

        Cat &operator=( const Cat &obj);

		void makeSound() const ;
		Brain* getBrain() const;
};