/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:30:06 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/08 16:51:02 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

static float find_area(const Point a, const Point b, const Point c) {
	float area;

	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
	
	area /= 2;
	if (area < 0)
		return( -area);
	return (area);

}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float	abc, abp, bcp, acp;
	bool	res = false;

	abc = find_area(a, b, c);
	abp = find_area(a, b, point);
	bcp  = find_area(b, c, point);
	acp = find_area(a, c, point);

	if (abp <= 0 || bcp <= 0 || acp <= 0)
		return res;
	if (abp + bcp + acp == abc)
		res = true;
	return res;
}