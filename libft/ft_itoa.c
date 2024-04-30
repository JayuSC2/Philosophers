/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:41:24 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 14:44:25 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	digit_count(int len)
{
	size_t	i;

	i = 1;
	while (len / 10)
	{
		len /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str_nb;
	long	num;
	size_t	digits;

	num = n;
	digits = digit_count(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_nb = (char *)malloc(sizeof(char) * digits + 1);
	if (!str_nb)
		return (NULL);
	*(str_nb + digits) = '\0';
	while (digits--)
	{
		*(str_nb + digits) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(str_nb + 0) = '-';
	return (str_nb);
}
/*
int	main(void)
{
	int	number1 = 1203;
	int	number2 = -1203;
	int	number3 = 0;

	printf("%s\n", ft_itoa(number1));
	printf("%s\n", ft_itoa(number2));
	printf("%s\n", ft_itoa(number3));
}
*/