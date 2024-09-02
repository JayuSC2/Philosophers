/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/09/02 17:01:31 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork");
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken the left fork");
    print_status(philo, "is eating");
	pthread_mutex_lock(&philo->m_data->death_lock);
	philo->last_meal = get_actual_time(philo->m_data->time);
	if (philo->last_meal == -1)
		philo->fatal = true;
	pthread_mutex_unlock(&philo->m_data->death_lock);
    smart_sleep(philo->m_data->time_to_eat, philo->m_data);
	print_status(philo, "finished eating");
	pthread_mutex_lock(&philo->m_data->meal_lock);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->m_data->meal_lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
void philo_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
    smart_sleep(philo->m_data->time_to_sleep, philo->m_data);
}
void philo_thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
    	usleep(100);
	if (philo->m_data->philo_count == 1)
		return (one_philo(philo), arg);
    while (1)
    {
		pthread_mutex_lock(&philo->m_data->death_lock);
        if (philo->m_data->death_flag == true)
            return (pthread_mutex_unlock(&philo->m_data->death_lock), arg);
		pthread_mutex_unlock(&philo->m_data->death_lock);
		if (philo->m_data->all_full == true || philo->fatal == true)
			return (arg);
        if (philo->is_full == false)
        {
            philo_eating(philo);
			if (philo->m_data->death_flag == false)
			{
				philo_sleeping(philo);
				philo_thinking(philo);
			}
        }
    }
    return (arg);
} 
