/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 18:45:05 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_thread_creation_error(pthread_t *threads,
	int i, t_metadata *m_data)
{
	pthread_mutex_lock(&m_data->death_lock);
	m_data->death_flag = true;
	pthread_mutex_unlock(&m_data->death_lock);
	while (--i >= 0)
	{
		if (pthread_join(threads[i], NULL) != 0)
			ft_putendl_fd("Error joining thread", 2);
	}
	free(threads);
	return (ft_putendl_fd("Error creating thread", 2), 1);
}

static int	create_threads(pthread_t *threads, t_metadata *m_data)
{
	int	i;

	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_create(&threads[i], NULL, &routine, &m_data->philo[i]) != 0)
			return (handle_thread_creation_error(threads, i, m_data));
		i++;
	}
	return (0);
}

static int	join_threads(pthread_t *threads, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			ft_putendl_fd("Error joining thread", 2);
		i++;
	}
	return (0);
}

int	create_philo(t_metadata *m_data)
{
	pthread_t	*threads;

	threads = (pthread_t *)malloc(m_data->philo_count * sizeof(pthread_t));
	if (threads == NULL)
		return (ft_putendl_fd("Error allocating memory for threads", 2), 1);
	m_data->start_time = get_current_time();
	if (m_data->start_time == -1)
		return (free(threads), 1);
	if (create_threads(threads, m_data) != 0)
		return (1);
	monitoring(m_data);
	join_threads(threads, m_data->philo_count);
	return (free(threads), 0);
}

/* int	create_philo(t_metadata *m_data)
{
	pthread_t	*threads;
	int			i;

	threads = (pthread_t *)malloc(m_data->philo_count * sizeof(pthread_t));
	if (threads == NULL)
		return (ft_putendl_fd("Error allocating memory for threads", 2), 1);
	m_data->start_time = get_current_time();
	if (m_data->start_time == -1)
		return (free(threads), 1);
	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_create(&threads[i], NULL, &routine, &m_data->philo[i]) != 0)
		{
			pthread_mutex_lock(&m_data->death_lock);
			m_data->death_flag = true;
			pthread_mutex_unlock(&m_data->death_lock);
			while (--i >= 0)
			{
				if (pthread_join(threads[i], NULL) != 0)
					ft_putendl_fd("Error joining thread", 2);
			}
			free(threads);
			return (ft_putendl_fd("Error creating thread", 2), 1);
		}
		i++;
	}
	monitoring(m_data);
	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_join(threads[i], NULL) != 0)
			ft_putendl_fd("Error joining thread", 2);
		i++;
	}
	return (free(threads), 0);
} */
