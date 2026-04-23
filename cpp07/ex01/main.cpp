#include <iostream>
#include <string>

#include "iter.hpp"

void increment(int &value) {
	++value;
}

template <typename T>
void printValue(T const &value) {
	std::cout << value << std::endl;
}

int main(void) {
	int numbers[] = {1, 2, 3, 4, 5};
	unsigned int numbersLen = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "numbers (original):" << std::endl;
	::iter(numbers, numbersLen, printValue<int>);

	::iter(numbers, numbersLen, increment);
	std::cout << "numbers (incremented):" << std::endl;
	::iter(numbers, numbersLen, printValue<int>);

	std::string words[] = {"template", "iter", "works"};
	unsigned int wordsLen = sizeof(words) / sizeof(words[0]);
	const std::string *constWords = words;

	std::cout << "words:" << std::endl;
	::iter(constWords, wordsLen, printValue<std::string>);
	return 0;
}
