#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <cstdio>
#include <string>
#include <ostream>

class BitcoinExchange
{
	private:
		std::map<std::time_t, float> _data;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string& path);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void addElement(std::string, float);
		float getValueOfDate(std::string) const;

		const std::map<std::time_t, float>& getData() const;
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& obj);

#endif
