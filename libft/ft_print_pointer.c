/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:55:38 by codespace         #+#    #+#             */
/*   Updated: 2024/01/02 16:47:03 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptr_len(unsigned long long num)
{
	unsigned int	counter;

	counter = 0;
	while (num != 0)
	{
		num /= 16;
		counter++;
	}
	return (counter);
}

void	put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		put_ptr (num / 16);
		put_ptr (num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
			ft_printchar(num - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
		counter += (write(1, "(nil)", 5));
	else
	{
		counter += write(1, "0x", 2);
		put_ptr(ptr);
		counter += ptr_len(ptr);
	}
	return (counter);
}
