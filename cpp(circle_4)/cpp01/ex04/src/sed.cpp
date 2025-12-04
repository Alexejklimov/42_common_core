/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:07:02 by oklimov           #+#    #+#             */
/*   Updated: 2025/12/04 14:27:06 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sed.hpp"

void sedIsForLosers(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty() || s1.empty())
	{
		std::cerr << RED << "Error. Filename, s1 must not be empty."
			<< NORM << std::endl;
		return;
	}

	std::string outputFilename = std::string(filename).append(".replaced");
	std::ifstream inputFile(filename.c_str());
	std::ofstream outputFile(outputFilename.c_str());

	if (!inputFile.is_open() || !outputFile.is_open())
	{
		std::cerr << RED << "Error: Could not open file(s)."
		<< NORM << std::endl;
		return;
	}
	std::string line;
	while (getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();	
}