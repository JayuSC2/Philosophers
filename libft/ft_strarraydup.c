/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraydup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:14:29 by juitz             #+#    #+#             */
/*   Updated: 2024/04/13 14:24:23 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarraydup(char **strarray)
{
	char	**strarraydup;
	int		i;
	int		rows;

	i = 0;
	while (strarray[i])
		i++;
	rows = i;
	strarraydup = (char **)malloc((rows + 1) * sizeof(char *));
	if (!strarraydup)
		return (NULL);
	i = 0;
	while (strarray[i])
	{
		strarraydup[i] = ft_strdup(strarray[i]);
		if (!strarraydup[i])
			return (ft_free(strarraydup), NULL);
		i++;
	}
	strarraydup[i] = NULL;
	return (strarraydup);
}
