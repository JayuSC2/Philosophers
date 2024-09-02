/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/09/02 15:36:58 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_m_data(t_metadata *m_data, int argc, char **argv)
{
	m_data->philo_count = ft_atoi(argv[1]);
	m_data->time_to_die = ft_atoi(argv[2]);
	m_data->time_to_eat = ft_atoi(argv[3]);
	m_data->time_to_sleep = ft_atoi(argv[4]);
	m_data->death_flag = false;
	m_data->all_full = false;
	if (argc == 6)
	{
		m_data->num_of_meals = ft_atoi(argv[5]);
		if (m_data->num_of_meals == 0)
			return (ft_putendl_fd("Error: num_of_meals can't be 0\n", 2), 1);
	}
	m_data->philo = (t_philo *)malloc(sizeof(t_philo) * m_data->philo_count);
	if (m_data->philo == NULL)
		return (1);
	m_data->time = (t_timer *)malloc(sizeof(t_timer));
	if (m_data->time == NULL)
		return (1);
	m_data->time->current_time = 0;
	m_data->time->time_passed = 0;
	m_data->time->start_time = get_current_time();
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
		m_data->philo[i].last_meal = get_actual_time(m_data->time);
		if (m_data->philo[i].last_meal == -1)
			return (ft_putendl_fd("Error: gettimeofday failed!", 2), 1);
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

int	mutex_init(t_metadata *m_data)
{
	if (forks_init(m_data) == 1)
		return (1);
	if (pthread_mutex_init(&m_data->print_lock, NULL) != 0
		|| pthread_mutex_init(&m_data->death_lock, NULL) != 0
		|| pthread_mutex_init(&m_data->meal_lock, NULL) != 0
		|| pthread_mutex_init(&m_data->time->time_lock, NULL) != 0)
		return (ft_putendl_fd("Error initializing mutex", 2), 1);
	return (0);
}
