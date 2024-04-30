/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:49:21 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 12:59:09 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
/*
int main(void)
{
	const char *str = "Des wird scho";
	size_t n  = 13;
	
	void *found = ft_memchr(str, 's', n);

	if (found != NULL)
		printf("%s\n", (char *)found);
	else
		printf("Character not found.\n");
	return (0);
}
*/