/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:46:03 by juitz             #+#    #+#             */
/*   Updated: 2024/01/02 16:45:04 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	if (s != 0)
	{
		write (1, s, ft_strlen(s));
	}
	return (ft_strlen(s));
}

/* int	main(void)
{
	char str[] = "";
	ft_putstr(str);
} 
 */