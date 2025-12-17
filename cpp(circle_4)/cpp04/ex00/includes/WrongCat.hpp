/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:21:28 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 10:49:48 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(); 

        ~WrongCat(); 

        WrongCat( const WrongCat &obj);

        WrongCat &operator=( const WrongCat &obj);

		void makeSound() const ;
};