/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:10:34 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 11:14:04 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;

	public:
		Animal();

		Animal(std::string type);

		Animal(const Animal& obj);

		Animal& operator=(const Animal& obj);

		virtual ~Animal();

		std::string	getType() const;
		
		virtual void makeSound() const;


};