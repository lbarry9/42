/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:15:25 by lbarry            #+#    #+#             */
/*   Updated: 2024/07/01 17:15:10 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_megaphone(char *word)
{
	int i = -1;

	while (word[++i])
		std::cout << (char)std::toupper(word[i]);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while (argv[++i])
			ft_megaphone(argv[i]);
	std::cout << std::endl;
	return (0);
}
