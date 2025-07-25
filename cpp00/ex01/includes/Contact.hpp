/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:07:10 by marcnava          #+#    #+#             */
/*   Updated: 2025/07/23 00:51:59 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <ctime>

using namespace std;

class Contact {
	private:
		string m_firstName;
		string m_lastName;
		string m_nickname;
		string m_phoneNumber;
		string m_darkestSecret;
		time_t m_createdAt;
	public:
		Contact();
		Contact(string &firstName, string &lastName, string &nickname,
			string &phoneNumber, string &darkestSecret);
		~Contact();
		string getFirstName();
		string getLastName();
		string getNickname();
		string getPhoneNumber();
		string getDarkestSecret();
		time_t getCratedAt();
};

#endif