/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:06 by juitz             #+#    #+#             */
/*   Updated: 2024/09/01 16:26:36 by juitz            ###   ########.fr       */
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
	int j;
	
	i = 1;
	j = 0;
	if (argc != 5 && argc != 6)
		 return (ft_putendl_fd("Error: Invalid number of arguments", 2), 1);
	while(i < argc)
	{
		if (argv[i][0] == '\0')
            return (ft_putendl_fd("Error: Empty argument", 2), 1);
		if (!ft_isnumber(argv[i]))
			return (ft_putendl_fd("Error: Non-numeric argument", 2), 1);
		i++;
	}
	if (check_overflow(argc, argv) == 1)
		return (ft_putendl_fd("Error: Argument overflow", 2), 1);
	return (0);
}

