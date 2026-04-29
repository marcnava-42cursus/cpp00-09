#include "BitcoinExchange.hpp"

#include <fstream>
#include <stdexcept>

namespace
{
	std::time_t validateDate(const std::string& date)
	{
		int			year;
		int			month;
		int			day;
		char		extra;
		std::tm		timeInfo;
		std::time_t	result;

		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			throw std::runtime_error("Error: bad input => " + date);
		if (std::sscanf(date.c_str(), "%d-%d-%d%c", &year, &month, &day, &extra) != 3)
			throw std::runtime_error("Error: bad input => " + date);
		timeInfo = std::tm();
		timeInfo.tm_year = year - 1900;
		timeInfo.tm_mon = month - 1;
		timeInfo.tm_mday = day;
		timeInfo.tm_hour = 0;
		timeInfo.tm_min = 0;
		timeInfo.tm_sec = 0;
		timeInfo.tm_isdst = -1;
		result = std::mktime(&timeInfo);
		if (result == static_cast<std::time_t>(-1)
			|| timeInfo.tm_year != year - 1900
			|| timeInfo.tm_mon != month - 1
			|| timeInfo.tm_mday != day)
			throw std::runtime_error("Error: bad input => " + date);
		return result;
	}

	void printDate(std::ostream& os, std::time_t date)
	{
		char	buffer[11];
		std::tm	*timeInfo;

		timeInfo = std::localtime(&date);
		if (timeInfo && std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo))
			os << buffer;
		else
			os << date;
	}

	void loadDatabase(BitcoinExchange& exchange, const std::string& path)
	{
		std::ifstream	file;
		std::string		line;
		std::string		date;
		std::string		valueStr;
		float			value;
		char			extra;
		std::size_t		comma;

		file.open(path.c_str());
		if (!file.is_open())
			throw std::runtime_error("Error: could not open database.");
		if (!std::getline(file, line) || line != "date,exchange_rate")
			throw std::runtime_error("Error: invalid database header.");
		while (std::getline(file, line))
		{
			if (line.empty())
				continue ;
			comma = line.find(',');
			if (comma == std::string::npos)
				throw std::runtime_error("Error: invalid database line => " + line);
			date = line.substr(0, comma);
			valueStr = line.substr(comma + 1);
			if (std::sscanf(valueStr.c_str(), "%f%c", &value, &extra) != 1)
				throw std::runtime_error("Error: invalid database line => " + line);
			exchange.addElement(date, value);
		}
	}
}

BitcoinExchange::BitcoinExchange(void)
{
	loadDatabase(*this, "data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& path)
{
	loadDatabase(*this, path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::addElement(std::string date, float value)
{
	_data[validateDate(date)] = value;
}

float BitcoinExchange::getValueOfDate(std::string date) const
{
	std::time_t									dateTime;
	std::map<std::time_t, float>::const_iterator	it;

	dateTime = validateDate(date);
	it = _data.lower_bound(dateTime);
	if (it != _data.end() && it->first == dateTime)
		return it->second;
	if (it == _data.begin())
		throw std::runtime_error("Error: bad input => " + date);
	--it;
	return it->second;
}

const std::map<std::time_t, float>& BitcoinExchange::getData() const
{
	return _data;
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& obj)
{
	std::map<std::time_t, float>::const_iterator it;
	const std::map<std::time_t, float>& data = obj.getData();

	os << "[";
	for (it = data.begin(); it != data.end(); ++it)
	{
		if (it != data.begin())
			os << ",";
		os << "(";
		printDate(os, it->first);
		os << "," << it->second << ")";
	}
	os << "]";
	return os;
}
