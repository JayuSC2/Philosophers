/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:18:06 by juitz             #+#    #+#             */
/*   Updated: 2023/09/25 13:18:06 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	get_word_len(const char *s, char c)
{
	if (!ft_strchr(s, c))
		return (ft_strlen(s));
	else
		return ((size_t)(ft_strchr(s, c) - s));
}

static char	**ft_freestrarray(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**split_strings;
	size_t	word_len;
	int		i;

	split_strings = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!split_strings)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = get_word_len(s, c);
			split_strings[i] = ft_substr(s, 0, word_len);
			if (!(split_strings[i++]))
				return (ft_freestrarray(split_strings), NULL);
			s += word_len;
		}
	}
	split_strings[i] = NULL;
	return (split_strings);
}
/* #include <stdio.h>
int main(void)
{
    char const *input = "This,is,a,test,string";
    char **result = ft_split(input, ',');
    
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("Token %d: %s\n", i, result[i]);
            i++;
        }
	}
    else
    {
        printf("ft_split returned NULL\n");
    }

    return 0;
} */
