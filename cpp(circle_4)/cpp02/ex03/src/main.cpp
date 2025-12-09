/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:00:33 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/09 09:52:31 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);      // inside
    Point outside(9, 9);    // outside
    Point edge(5, 0);      // on edge
    Point top(0, 0);      // on top


    std::cout << "inside: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "outside: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "edge: " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl;
    std::cout << "top: " << (bsp(a, b, c, top) ? "true" : "false") << std::endl;

    return 0;
}
