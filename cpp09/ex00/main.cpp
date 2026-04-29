#include "BitcoinExchange.hpp"

#include <exception>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

namespace
{
	float	parseValue(const std::string& valueStr, const std::string& line)
	{
		float	value;
		char	extra;

		if (std::sscanf(valueStr.c_str(), "%f%c", &value, &extra) != 1)
			throw std::runtime_error("Error: bad input => " + line);
		if (value != value)
			throw std::runtime_error("Error: bad input => " + line);
		if (value < 0)
			throw std::runtime_error("Error: not a positive number.");
		if (value > 1000)
			throw std::runtime_error("Error: too large a number.");
		return value;
	}

	void	processLine(const BitcoinExchange& exchange, const std::string& line)
	{
		std::string	date;
		std::string	valueStr;
		float		value;
		float		rate;
		std::size_t	separator;

		separator = line.find(" | ");
		if (separator == std::string::npos)
			throw std::runtime_error("Error: bad input => " + line);
		date = line.substr(0, separator);
		valueStr = line.substr(separator + 3);
		value = parseValue(valueStr, line);
		rate = exchange.getValueOfDate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}

	void	processInputLine(const BitcoinExchange& exchange, const std::string& line)
	{
		try
		{
			processLine(exchange, line);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	input;
	std::string		line;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;

		input.open(argv[1]);
		if (!input.is_open())
			throw std::runtime_error("Error: could not open file.");
		if (std::getline(input, line) && line != "date | value")
			processInputLine(exchange, line);
		while (std::getline(input, line))
			processInputLine(exchange, line);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
