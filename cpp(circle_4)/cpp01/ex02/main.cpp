/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:01:12 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/02 12:20:16 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "this is string address -> " << &str << std::endl;
	std::cout << "this is pointer address -> " << stringPTR << std::endl;
	std::cout << "this is reference address -> " << &stringREF << std::endl;
	
	std::cout << "\n";
	
	std::cout << "this is string value -> " << str << std::endl;
	std::cout << "this is pointer value -> " << *stringPTR << std::endl;
	std::cout << "this is reference value -> " << stringREF << std::endl;

	return (0);
}