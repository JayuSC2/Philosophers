/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:17:01 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 14:43:38 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start >= end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	trim = malloc(end - start + 2);
	if (!trim)
		return (NULL);
	ft_strlcpy (trim, &s1[start], end - start + 2);
	return (trim);
}
/*
int	main(void)
{
	char const *s1 = "    HELLO   ";
	char const *set = " ";

	printf ("%s", ft_strtrim(s1, set));
}
*/