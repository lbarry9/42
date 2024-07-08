/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:03:17 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/05 22:12:29 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

std::string	find_and_replace(std::string line, const std::string &s1, const std::string &s2)
{
	size_t found = 0;
	while ((found = line.find(s1)) != std::string::npos)
	{
		line = line.substr(0, found) + s2 + line.substr(found + s1.length());
		found += s2.length();
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please enter 3 arguments: an infile and 2 strings." << std::endl;
		return (1);
	}

	const char 			*infile = argv[1];
	std::string			outfile(infile);
	std::string			line;

	std::ifstream		file(infile);
	if (!file.is_open())
	{
		std::cerr << "Failed to open input file." << std::endl;
		return (1);
	}

	std::ofstream		out;
	outfile.append(".replace");
	out.open(outfile.c_str(), std::ios_base::app);
	if (!out.is_open())
	{
		std::cerr << "Failed to open output file." << std::endl;
		return (1);
	}

	while (std::getline(file, line))
	{
		std::string replaced = find_and_replace(line, argv[2], argv[3]);
		out << replaced << std::endl;
	}
	file.close();
	out.close();
	return (0);
}
