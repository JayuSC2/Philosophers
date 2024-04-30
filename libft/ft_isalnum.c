/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:48:44 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 14:29:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_digit(int num)
{
	if (num >= 48 && num <= 57)
		return (1);
	else
		return (0);
}

static int	is_alpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(int input)
{
	return (is_digit(input) || is_alpha(input));
}
/*
int	main(void)
{
	printf ("%d", ft_isalnum(';'));
	printf ("%d", ft_isalnum('-'));
	printf ("%d", ft_isalnum('0'));
	printf ("%d", ft_isalnum('A'));
}
*/