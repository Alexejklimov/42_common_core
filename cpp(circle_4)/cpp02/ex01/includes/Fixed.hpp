/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:55:41 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/09 09:42:39 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#pragma once

class Fixed {
	private:
		int value;
		static const int fractBit = 8;
	
	public:
		Fixed();

		Fixed(const int n);

		Fixed(const float f);

		Fixed(const Fixed &obj);

		Fixed &operator=(const Fixed &obj);

		~Fixed();

		int		getRawBits (void) const;
		void	setRawBits(int const raw);

		float	toFloat( void )const;
		int		toInt( void )const;
};

std::ostream &operator << (std::ostream &os, const Fixed &fixed);
