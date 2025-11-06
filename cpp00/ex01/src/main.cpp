/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:35:51 by marcnava          #+#    #+#             */
/*   Updated: 2025/10/16 19:12:33 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <limits>

#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define reset "\033[0m"

#define App '\t' << green << "ADD" << reset << ": Add a new contact entry." << std::endl
#define Spp '\t' << yellow << "SEARCH" << reset << ": Search an specific contact." << std::endl
#define Xpp '\t' << red << "EXIT" << reset << ": Exit the program."
#define I red << "Invalid Option!: "

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout.flush();
}

bool isOnlyWhitespace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

std::string checkField(std::string fieldMsg)
{
	std::string input = "";
	while (input.length() == 0 || isOnlyWhitespace(input))
	{
		std::cout << fieldMsg << ": ";
		if (!getline(std::cin, input))
			exit(1);
	}
	return input;
}

void addContact(PhoneBook *pb)
{
	std::string tmp;
	clearScreen();
	pb->addContact(
		checkField("Enter first name"),
		checkField("Enter last name"),
		checkField("Enter nickname"),
		checkField("Enter phone number"),
		checkField("Enter darkest secret")
	);
	std::cout << "Contact added successfully, press any key to continue" << std::endl;
	getchar();
	clearScreen();
}

void printCell(std::string text, bool nl)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	std::cout << std::setfill(' ') << std::setw(10) << text << (nl ? "|\n" : "|");
}

void printHeader(void)
{
	std::cout << '|';
	printCell("Index", false);
	printCell("First Name", false);
	printCell("Last Name", false);
	printCell("Nickname", true);
}

void printContacts(PhoneBook *pb)
{
	for (int i = 0; i < pb->getNumberEntries(); i++)
	{
		Contact contact = pb->getContact(i);
		std::cout << '|';
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		printCell(contact.getFirstName(), false);
		printCell(contact.getLastName(), false);
		printCell(contact.getNickname(), true);
	}
}

void printContact(Contact contact)
{
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int main(void)
{
	std::string cmd;
	PhoneBook pb;
	bool i = false;

	clearScreen();
	while(true)
	{
		i ? std::cout << I << cmd << reset << std::endl : std::cout << std::endl;
		std::cout << std::endl << "Options: " << std::endl << App << Spp << Xpp << std::endl;
		std::cout << "Enter an option: ";

		if ( !(getline(std::cin, cmd)))
			return 1;
		clearScreen();
		if ( cmd.compare("ADD") == 0)
		{
			i = false;
			addContact(&pb);
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			int index = -1;
			clearScreen();
			i = false;
			printHeader();
			printContacts(&pb);
			std::cout << "Select an contact index: ";
			std::cin >> index;
			if (index > 0 && index <= pb.getNumberEntries())
				printContact(pb.getContact(index - 1));
			else
				std::cout << "Invalid index" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Press any key to continue" << std::endl;
			getchar();
			clearScreen();
		}
		else if (cmd.compare("EXIT") == 0)
			break;
		else
			i = true;
	}
}
