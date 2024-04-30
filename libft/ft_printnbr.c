/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:27:12 by julian            #+#    #+#             */
/*   Updated: 2024/01/13 21:27:40 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int num)
{
	int	counter;

	counter = 0;
	if (num == -2147483648)
		return (11);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		counter++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

void	ft_putnbr(int n)
{
	char	nb;

	if (n < 0 && n > -2147483648)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n < 10)
	{
		nb = n + '0';
		write(1, &nb, 1);
	}
	if (n >= 10 && n <= 2147483647)
	{
		ft_printnbr(n / 10);
		ft_printnbr(n % 10);
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
}

int	ft_printnbr(int n)
{
	ft_putnbr(n);
	return (nbr_len(n));
}
