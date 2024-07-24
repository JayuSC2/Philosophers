/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:06 by juitz             #+#    #+#             */
/*   Updated: 2024/07/24 18:19:56 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_overflow(int argc, char **argv)
{
	long int	num;
	int			i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int input)
{
	if (input >= 48 && input <= 57)
		return (1);
	else
		return (0);
}
int	isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc != 5 && argc != 6)
		return (printf("Error: Invalid number of arguments\n"), 1);
	// while(argv[i])
	// {
	// 	if (argv[i][j] == '\0')
	// 		return (printf("Error: empty argument"));
	// 	i++;
	// }
	if (argv[i] == NULL || check_overflow(argc, argv) == 1)
		return (1);
	if (isnumber(argv[i]) == 0)
		return (1);
	return (0);
}

