/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:02:50 by juitz             #+#    #+#             */
/*   Updated: 2023/09/26 14:47:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (((size_t) -1) < nitems * size)
		return (NULL);
	ptr = (void *)malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nitems);
	return (ptr);
}
/*
int main(void)
{
	size_t nitems = 5;
	size_t size = sizeof(int);
	size_t i = 0;
	int *array = (int *)ft_calloc(nitems, size);

	if(array == NULL)
	printf ("Memory allocation failed!\n");
	return (1);

	while (i < nitems)
		i++;
	array[i] = 1 * 10;

	while (i < nitems)
		printf("array[%zu] = %d\n", i, array[i]);
	free(array);
	return (0);
}
*/