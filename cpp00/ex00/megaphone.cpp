/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarcell <jmarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:25 by jmarcell          #+#    #+#             */
/*   Updated: 2025/07/22 18:49:47 by jmarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include <iostream>
#include <cctype>

void ft_put_upper_str(char *str)
{
	for (;*str != '\0';str++)
		isalpha(*str) ? cout << (char)toupper(*str) : cout << *str;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
		ft_put_upper_str(argv[i]);
	cout << endl;
	return 0;
}
