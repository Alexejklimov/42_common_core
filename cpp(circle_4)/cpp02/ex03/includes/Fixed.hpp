/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:55:41 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/08 15:50:19 by oklimov          ###   ########.fr       */
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

		Fixed(const Fixed& obj);

		Fixed &operator=(const Fixed& obj);

		~Fixed();

		int getRawBits (void) const;

		void setRawBits(int const raw);

		float toFloat( void )const;
		int toInt( void )const;

		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj)const;
		bool operator<=(const Fixed &obj)const;
		bool operator==(const Fixed &obj)const;
		bool operator!=(const Fixed &obj)const;

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed &operator++(); 
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator << (std::ostream &os, const Fixed &fixed);
