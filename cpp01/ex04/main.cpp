/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:34:37 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/26 20:12:03 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string get_replaced_line(const std::string src,
	std::string target, std::string replace)
{
	int init = 0;
	std::cout << src.find(target, init) << std::endl;
	if (!src.c_str())
		replace = "";
	return "";
}

int main(int argc, char **argv)
{
	std::string line_buffer;

	if (argc < 4)
	{
		std::cout << "Error: Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return 0;
	}
	
	std::string ifile = argv[1];
	std::string ofile = ifile + ".replace";
	std::string target = argv[2];
	std::string replace = argv[3];
	
	std::ifstream in(ifile.c_str());
	std::ofstream out(ofile.c_str());

	if (in.is_open())
	{
		while (std::getline(in, line_buffer))
		{
			line_buffer = get_replaced_line(line_buffer, target, replace);
			out << line_buffer;
			if (!in.eof())
				out << std::endl;
		}
	}
}
