/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:35:51 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/22 21:13:01 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <iomanip>
#include <limits>

#define c1 "\033[31m"
#define c2 "\033[32m"
#define c3 "\033[33m"
#define r "\033[0m"

#define A "ADD"
#define App '\t' << c3 << A << r << ": Add a new contact entry." << std::endl
#define S "SEARCH"
#define Spp '\t' << c2 << S << r << ": Search an specific contact." << std::endl
#define X "EXIT"
#define Xpp '\t' << c1 << X << r << ": Exit the program."
#define I c1 << "Invalid Option!: "
#define E "Enter an option: "
#define O "Options: "

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout.flush();
}

std::string checkField(std::string fieldMsg)
{
	std::string input = "";
	for (;input.length() == 0;)
	{
		std::cout << fieldMsg << ": ";
		getline(std::cin, input);
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
		std::cout << '|';
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		printCell(pb->contacts[i].getFirstName(), false);
		printCell(pb->contacts[i].getLastName(), false);
		printCell(pb->contacts[i].getPhoneNumber(), true);
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
		i ? std::cout << I << cmd << r << std::endl : std::cout << std::endl;
		std::cout << std::endl << O << std::endl << App << Spp << Xpp << std::endl;
		std::cout << E;

		if ( !(getline(std::cin, cmd)))
			return 1;
		clearScreen();
		if ( cmd.compare(A) == 0)
		{
			i = false;
			addContact(&pb);
		}
		else if (cmd.compare(S) == 0)
		{
			int index = -1;
			clearScreen();
			i = false;
			printHeader();
			printContacts(&pb);
			std::cout << "Select an contact index: ";
			std::cin >> index;
			if (index > 0 && index <= pb.getNumberEntries())
				printContact(pb.contacts[index - 1]);
			else
				std::cout << "Invalid index" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Press any key to continue" << std::endl;
			getchar();
			clearScreen();
		}
		else if (cmd.compare(X) == 0)
			break;
		else
			i = true;
	}
}
