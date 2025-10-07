/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:34:37 by marcnava          #+#    #+#             */
/*   Updated: 2025/10/07 21:07:47 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::string;

using std::cin;
using std::cout;

using std::endl;

static std::string get_replaced_line(string src, string target, string replace)
{
	size_t	start = 0;

	while ((start = src.find(target, start)) != string::npos)
	{
		src = src.substr(0, start);
		src += replace;
		src += src.substr(start, target.length());
		start = replace.length();
	}
	return src;
}

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		cout << "Error: Usage: " << argv[0] << " <filename> <str1> <str2>" << endl;
		return 0;
	}
	
	string line_buffer;
	string ifile = argv[1];
	string ofile = ifile + ".replace";
	string target = argv[2];
	string replace = argv[3];
	
	std::ifstream in(ifile.c_str());
	std::ofstream out(ofile.c_str());

	if (in.is_open())
	{
		while (std::getline(in, line_buffer))
		{
			line_buffer = get_replaced_line(line_buffer, target, replace);
			out << line_buffer;
			if (!in.eof())
				out << endl;
		}
		in.close();
		out.close();
	}
	else
		cout << "Error: Failed to open the file" << endl;
	return 0;
}
