/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/22 13:35:58 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_variables(t_metadata *m_data, int argc, char **argv)
{	
	m_data->philo_count = ft_atoi(argv[1]);
	m_data->time_to_die = ft_atoi(argv[2]);
	m_data->time_to_eat = ft_atoi(argv[3]);
	m_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		m_data->num_of_meals = ft_atoi(argv[5]);
	m_data->time = (t_timer *)malloc(sizeof(t_timer));
    if (m_data->time == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
	m_data->time->start_time = get_current_time();
	m_data->philo = (t_philo *)malloc(sizeof(t_philo) * m_data->philo_count);
	if (m_data->philo == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	return (0);
}

int	mutex_init(t_metadata *m_data)
{
	int i;

	m_data->philo->fork = malloc (sizeof(pthread_mutex_t) * m_data->philo_count);
	if (m_data->philo->fork == NULL)
	{
		printf("Error allocating memory");
		return (1);
	}
	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_init(&m_data->philo->fork[i], NULL) != 0)
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

	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_destroy(&m_data->philo->fork[i]) != 0)
		{
			printf("Error destroying mutex\n");
			return (1);
		}
		i++;
	}
	printf("test6\n");
	free(m_data->philo->fork);
	return (0);
}

