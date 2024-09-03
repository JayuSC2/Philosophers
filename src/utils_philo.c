/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:51:17 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 15:32:45 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	print_status(t_philo *philo, char *status)
{
	int	actual_time;
	
	// pthread_mutex_lock(&philo->m_data->death_lock);
	// if (philo->m_data->death_flag)
	// 	return (pthread_mutex_unlock(&philo->m_data->death_lock), 0);
	// pthread_mutex_unlock(&philo->m_data->death_lock);
	pthread_mutex_lock(&philo->m_data->print_lock);
	actual_time = get_current_time();
	if (actual_time == -1)
	{
		pthread_mutex_lock(&philo->m_data->death_lock);
		philo->fatal = true;
		pthread_mutex_unlock(&philo->m_data->death_lock);
	}
	pthread_mutex_lock(&philo->m_data->death_lock);
	if (philo->m_data->death_flag)
		return (pthread_mutex_unlock(&philo->m_data->death_lock),
			pthread_mutex_unlock(&philo->m_data->print_lock), 0);
	pthread_mutex_unlock(&philo->m_data->death_lock);
	printf("%d %d %s\n", actual_time - philo->m_data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->m_data->print_lock);
	return (0);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork");
	smart_sleep(philo->m_data->time_to_eat, philo->m_data);
	pthread_mutex_unlock(philo->right_fork);
}
