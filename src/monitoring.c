/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 18:33:42 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_metadata *m_data, int i, int current_time)
{
	int	death_time;

	pthread_mutex_lock(&m_data->meal_lock);
	death_time = current_time - m_data->philo[i].last_meal;
	pthread_mutex_unlock(&m_data->meal_lock);
	if (death_time > m_data->time_to_die)
	{
		print_status(&m_data->philo[i], "died");
		pthread_mutex_lock(&m_data->death_lock);
		m_data->death_flag = true;
		pthread_mutex_unlock(&m_data->death_lock);
		return (1);
	}
	return (0);
}

static int	check_fullness(t_metadata *m_data, int *full_count)
{
	int	i;

	i = 0;
	while (i < m_data->philo_count)
	{
		pthread_mutex_lock(&m_data->meal_lock);
		if (m_data->philo[i].meal_counter >= m_data->num_of_meals
			&& m_data->num_of_meals != 0)
			(*full_count)++;
		pthread_mutex_unlock(&m_data->meal_lock);
		i++;
	}
	if (*full_count == m_data->philo_count)
	{
		pthread_mutex_lock(&m_data->meal_lock);
		m_data->all_full = true;
		pthread_mutex_unlock(&m_data->meal_lock);
		return (1);
	}
	return (0);
}

static int	check_philos(t_metadata *m_data)
{
	int	i;
	int	current_time;

	i = 0;
	while (i < m_data->philo_count)
	{
		current_time = get_current_time();
		if (current_time == -1)
			return (1);
		if (check_death(m_data, i, current_time))
			return (1);
		i++;
	}
	return (0);
}

int	monitoring(t_metadata *m_data)
{
	int	full_count;

	while (1)
	{
		full_count = 0;
		pthread_mutex_lock(&m_data->death_lock);
		if (m_data->death_flag)
			return (pthread_mutex_unlock(&m_data->death_lock), 1);
		pthread_mutex_unlock(&m_data->death_lock);
		if (check_philos(m_data))
			return (1);
		if (check_fullness(m_data, &full_count))
			break ;
	}
	return (0);
}
