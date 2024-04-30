/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:46:20 by codespace         #+#    #+#             */
/*   Updated: 2024/01/02 16:46:47 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int num)
{
	int	counter;

	counter = 0;
	while (num != 0)
	{
		num /= 16;
		counter++;
	}
	return (counter);
}

void	put_hexa_lc(unsigned int num)
{
	if (num >= 16)
	{
		put_hexa_lc(num / 16);
		put_hexa_lc(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
			ft_printchar(num - 10 + 'a');
	}
}

int	ft_print_hex_lc(unsigned int num)
{
	if (num == 0)
		return (ft_printchar('0'));
	put_hexa_lc(num);
	return (hex_len(num));
}

/* 
void    *put_hexa_lc(unsigned int num, const char *format)
{
    if (num >= 16)
        {
            put_hexa_lc(num % 16, *format);
            put_hexa_lc(num / 16, *format);
        }
    else
    {
        if (num <= 9)
            ft_printchar(num + '0');
        else
        {
            if (*format == 'x')
                ft_printchar(num - 10 + 'a');
            if (*format == 'X')
                ft_printchar(num - 10 + 'A');
        }
    }
} */