/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/19 16:19:29 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_variables(t_metadata *m_data, char **argv)
{
	m_data->philo_count = ft_atoi(argv[1]);
	m_data->time_to_die = ft_atoi(argv[2]);
	m_data->time_to_eat = ft_atoi(argv[3]);
	m_data->time_to_sleep = ft_atoi(argv[4]);
	m_data->num_of_meals = ft_atoi(argv[5]);
	m_data->time.start_time = get_current_time();
	return (0);
}

int	mutex_init(t_metadata *m_data)
{
	int i;

	m_data->philo.fork = malloc (sizeof(pthread_mutex_t) * m_data->philo_count);
	i = 1;
	while (i <= m_data->philo_count)
	{
		if (pthread_mutex_init(&m_data->philo.fork[i], NULL) != 0)
		{
			printf("Error initializing mutex\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	destroy_mutex(t_metadata *m_data)
{
	int i;

	i = 1;
	while (i <= m_data->philo_count)
	{
		if (pthread_mutex_destroy(&m_data->philo.fork[i]) != 0)
		{
			printf("Error destroying mutex\n");
			return (1);
		}
		i++;
	}
	free(m_data->philo.fork);
	return (0);
}

