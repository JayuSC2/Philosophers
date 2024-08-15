/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/15 13:09:09 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_philo *philo)
{
	int i;

	philo->fork = malloc (sizeof(pthread_mutex_t) * philo->philo_count);
	i = 1;
	while (i <= philo->philo_count)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
		{
			printf("Error initializing mutex\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	destroy_mutex(t_philo *philo)
{
	int i;

	i = 1;
	while (i <= philo->philo_count)
	{
		if (pthread_mutex_destroy(&philo->fork[i]) != 0)
		{
			printf("Error destroying mutex\n");
			return (1);
		}
		i++;
	}
	free(philo->fork);
	return (0);
}

