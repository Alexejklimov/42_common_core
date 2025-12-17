/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:36:18 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/17 13:10:30 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Brain {
	protected:
		std::string ideas[100];
	public:
		Brain();
		
		~Brain(); 
		
		Brain(const Brain& obj);
		
		Brain &operator=(const Brain& obj);
};