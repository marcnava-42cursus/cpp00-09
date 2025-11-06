/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:07:10 by marcnava          #+#    #+#             */
/*   Updated: 2025/08/22 21:09:32 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <ctime>
# include <iostream>

class Contact {
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
		time_t m_createdAt;
	public:
		Contact();
		Contact(std::string &firstName, std::string &lastName, std::string &nickname,
			std::string &phoneNumber, std::string &darkestSecret);
		~Contact();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		time_t getCreatedAt();
};

#endif