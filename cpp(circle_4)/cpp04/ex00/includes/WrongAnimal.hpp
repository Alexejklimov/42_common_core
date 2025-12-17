/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:12:20 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/16 15:19:54 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal();

		~WrongAnimal();

		WrongAnimal(const WrongAnimal& obj);

		WrongAnimal &operator=(const WrongAnimal& obj);

		
		std::string getType() const;
		void makeSound() const;
};