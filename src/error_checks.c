/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:06 by juitz             #+#    #+#             */
/*   Updated: 2024/08/22 13:20:56 by julian           ###   ########.fr       */
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
int	ft_isnumber(char *str)
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
	
	i = 1;
	if (argc != 5 && argc != 6)
		 return (printf("Error: Invalid number of arguments\n"), 1);
	while(i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (printf("Error: Non-numeric argument\n"), 1);
		i++;
	}
	if (check_overflow(argc, argv) == 1)
		return (printf("Error: Argument overflow\n"), 1);
	return (0);
}

