/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:21:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/08 16:29:18 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(): _x(0), _y(0)
{
	//"Default construcor called" 
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	//"Constructor called"

}

Point::Point(const Point& obj): _x(obj.getX()), _y(obj.getY())
{
	//"Copy Constructor called"
}

Point::~Point() {
	//"Destructor called"
}

const Fixed &Point::getX(void)const {
	return (this->_x);
}

const Fixed &Point::getY(void)const {
	return (this->_y);
}

std::ostream	&operator<<(std::ostream &os, Point const point)
{
	os << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (os);
}