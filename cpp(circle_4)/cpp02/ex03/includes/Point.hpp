/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:41:25 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/09 09:51:17 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

#pragma once

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		~Point();

		Point &operator=(const Point& obj);

		const Fixed& getX(void)const;
		const Fixed& getY(void)const;

};

std::ostream &operator << (std::ostream &os, const Fixed &fixed);
