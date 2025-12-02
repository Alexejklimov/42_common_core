/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:32:26 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 15:00:54 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

class Weapon {
	private:
		std::string type;

	public:
		Weapon(const std::string& type);
		~Weapon();

		const std::string getType();

		void setType(std::string type);
};
