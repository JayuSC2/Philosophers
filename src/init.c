/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/26 15:09:52 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_variables(t_philo *philo, int argc, char **argv)
{	
	philo->m_data = (t_metadata *)malloc(sizeof(t_metadata));
    if (philo->m_data == NULL)
	{
        return (1);
	}
	philo->m_data->philo_count = ft_atoi(argv[1]);
	philo->m_data->time_to_die = ft_atoi(argv[2]);
	philo->m_data->time_to_eat = ft_atoi(argv[3]);
	philo->m_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->m_data->num_of_meals = ft_atoi(argv[5]);
	philo->time = (t_timer *)malloc(sizeof(t_timer));
    if (philo->time == NULL)
	{
        return (1);
	}
	philo->time->current_time = 0;
	philo->time->time_passed = 0;
	philo->time->start_time = get_current_time();
	philo = (t_philo *)malloc(sizeof(t_philo) * philo->m_data->philo_count);
	if (philo == NULL)
	{
		return (1);
	}
	return (0);
}

int	forks_init(t_metadata *m_data)
{
	int i;

	m_data->forks = malloc (sizeof(pthread_mutex_t) * m_data->philo_count);
	if (m_data->forks == NULL)
	{
		printf("Error allocating memory");
		return (1);
	}
	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_init(&m_data->forks[i], NULL) != 0)
		{
			destroy_mutex(m_data);
			printf("Error initializing mutex\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	print_init(t_metadata *m_data)
{
	if (pthread_mutex_init(&m_data->print_lock, NULL) != 0)
	{
		printf("Error initializing print mutex\n");
		return (1);
	}
	return (0);
}

int	mutex_init(t_metadata *m_data)
{
	if (forks_init(m_data) == 1)
		return (1);
	if (print_init(m_data) == 1)
		return (1);
	return (0);
}

int	destroy_mutex(t_metadata *m_data)
{
	int i;

	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_destroy(&m_data->forks[i]) != 0)
		{
			printf("Error destroying mutex\n");
			return (1);
		}
		i++;
	}
	free(m_data->forks);
	return (0);
}

