/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:45:43 by oklimov           #+#    #+#             */
/*   Updated: 2025/11/25 12:38:26 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string phrase = av[i];
		for (size_t j = 0; j < phrase.length(); j++)
		{
			char c = phrase[j];
			if (isalpha(static_cast<unsigned char>(c)))
			{
				c = std::toupper(static_cast<unsigned char>(c));
				std::cout << c;
			}
			else
			{
				std::cout << c;
			}
		}
	}
	std::cout << '\n';
	return (0);
}
