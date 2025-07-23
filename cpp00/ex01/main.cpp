/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:35:51 by marcnava          #+#    #+#             */
/*   Updated: 2025/07/23 19:00:37 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <iomanip>
#include <limits>

using namespace std;

#define c1 "\033[31m"
#define c2 "\033[32m"
#define c3 "\033[33m"
#define r "\033[0m"

#define A "ADD"
#define App '\t' << c3 << A << r << ": Add a new contact entry." << endl
#define S "SEARCH"
#define Spp '\t' << c2 << S << r << ": Search an specific contact." << endl
#define X "EXIT"
#define Xpp '\t' << c1 << X << r << ": Exit the program."
#define I c1 << "Invalid Option!: "
#define E "Enter an option: "
#define O "Options: "

void clearScreen()
{
	cout << "\033[2J\033[1;1H";
	cout.flush();
}

string checkField(string fieldMsg)
{
	string input = "";
	for (;input.length() == 0;)
	{
		cout << fieldMsg << ": ";
		getline(cin, input);
	}
	return input;
}

void addContact(PhoneBook *pb)
{
	string tmp;
	clearScreen();
	pb->addContact(
		checkField("Enter first name"),
		checkField("Enter last name"),
		checkField("Enter nickname"),
		checkField("Enter phone number"),
		checkField("Enter darkest secret")
	);
	cout << "Contact added successfully, press any key to continue" << endl;
	getchar();
	clearScreen();
}

void printCell(string text, bool nl)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	cout << setfill(' ') << setw(10) << text << (nl ? "|\n" : "|");
}

void printHeader(void)
{
	cout << '|';
	printCell("Index", false);
	printCell("First Name", false);
	printCell("Last Name", false);
	printCell("Nickname", true);
}

void printContacts(PhoneBook *pb)
{
	for (int i = 0; i < pb->getNumberEntries(); i++)
	{
		cout << '|';
		cout << setfill(' ') << setw(10) << i + 1 << "|";
		printCell(pb->contacts[i].getFirstName(), false);
		printCell(pb->contacts[i].getLastName(), false);
		printCell(pb->contacts[i].getPhoneNumber(), true);
	}
}

void printContact(Contact contact)
{
	cout << "First Name: " << contact.getFirstName() << endl;
	cout << "Last Name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone Number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
}

int main(void)
{
	string cmd;
	PhoneBook pb;
	bool i = false;

	clearScreen();
	while(true)
	{
		i ? cout << I << cmd << r << endl : cout << endl;
		cout << endl << O << endl << App << Spp << Xpp << endl;
		cout << E;

		if ( !(getline(cin, cmd)))
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
			cout << "Select an contact index: ";
			cin >> index;
			if (index > 0 && index <= pb.getNumberEntries())
				printContact(pb.contacts[index - 1]);
			else
				cout << "Invalid index" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Press any key to continue" << endl;
			getchar();
			clearScreen();
		}
		else if (cmd.compare(X) == 0)
			break;
		else
			i = true;
	}
}
