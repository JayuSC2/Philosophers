/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:31:02 by juitz             #+#    #+#             */
/*   Updated: 2023/09/18 10:31:02 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == 0 && little == 0)
		return (NULL);
	if (little[j] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && little[j] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
	const char big [] = "San a poa Huankinda dabei";
	const char little [] = "Huankinda";
	size_t  len = 20;

	printf("%s", ft_strnstr(big, little, len));
}
*/