/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:06 by juitz             #+#    #+#             */
/*   Updated: 2024/05/02 11:38:13 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *str)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

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

int ft_check_args(int argc, char **argv)
{
	int i;

	i = 0;
	
}

