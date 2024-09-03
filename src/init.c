/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 17:25:19 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	init_m_data(t_metadata *m_data, int argc, char **argv)
{
	m_data->philo_count = ft_atoi(argv[1]);
	m_data->time_to_die = ft_atoi(argv[2]);
	m_data->time_to_eat = ft_atoi(argv[3]);
	m_data->time_to_sleep = ft_atoi(argv[4]);
	m_data->start_time = get_current_time();
	if (m_data->start_time == -1)
		return (1);
	m_data->death_flag = false;
	m_data->all_full = false;
	if (argc == 6)
	{
		m_data->num_of_meals = ft_atoi(argv[5]);
		if (m_data->num_of_meals == 0)
			return (ft_putendl_fd("Error: num_of_meals can't be 0", 2), 1);
	}
	m_data->philo = (t_philo *)malloc(sizeof(t_philo) * m_data->philo_count);
	if (m_data->philo == NULL)
		return (ft_putendl_fd("Error: malloc for philo failed", 2), 1);
	return (0);
}

int	init_philos(t_metadata *m_data)
{
	int	i;

	i = 0;
	while (i < m_data->philo_count)
	{
		m_data->philo[i].id = i + 1;
		m_data->philo[i].left_fork = &m_data->forks[i];
		m_data->philo[i].right_fork = &m_data->forks[
			(i + 1) % m_data->philo_count];
		m_data->philo[i].is_full = false;
		m_data->philo[i].fatal = false;
		m_data->philo[i].last_meal = get_current_time();
		if (m_data->philo[i].last_meal == -1)
			return (1);
		m_data->philo[i].meal_counter = 0;
		m_data->philo[i].m_data = m_data;
		i++;
	}
	return (0);
}

int	forks_init(t_metadata *m_data)
{
	int	i;

	m_data->forks = malloc(sizeof(pthread_mutex_t) * m_data->philo_count);
	if (m_data->forks == NULL)
		return (ft_putendl_fd("Error allocating memory", 2), 1);
	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_init(&m_data->forks[i], NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&m_data->forks[i]);
			}
			free(m_data->forks);
			return (ft_putendl_fd("Error initializing mutex", 2), 1);
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_metadata *m_data)
{
	if (pthread_mutex_init(&m_data->print_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&m_data->death_lock, NULL) != 0)
		return (pthread_mutex_destroy(&m_data->print_lock), 1);
	if (pthread_mutex_init(&m_data->meal_lock, NULL) != 0)
		return (pthread_mutex_destroy(&m_data->print_lock),
			pthread_mutex_destroy(&m_data->death_lock), 1);
	if (forks_init(m_data) == 1)
		return (pthread_mutex_destroy(&m_data->print_lock),
			pthread_mutex_destroy(&m_data->death_lock),
			pthread_mutex_destroy(&m_data->meal_lock), 1);
	return (0);
}
