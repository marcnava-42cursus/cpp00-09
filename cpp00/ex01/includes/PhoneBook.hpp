/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:31:45 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/22 21:10:02 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <ctime>
# include <iostream>

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		int m_totalContacts;
		Contact contacts[MAX_CONTACTS];

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact &contact);
		void addContact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret);
		int getNumberEntries();
		Contact getContact(int index);
};

#endif