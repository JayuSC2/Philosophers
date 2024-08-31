/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/08/31 13:01:44 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo->left_fork_locked = 1;
	print_status(philo, "has taken the left fork");
    pthread_mutex_lock(philo->right_fork);
	philo->right_fork_locked = 1;
	print_status(philo, "has taken the right fork");
    print_status(philo, "is eating");
	pthread_mutex_lock(&philo->m_data->eating_lock);
	philo->last_meal = get_actual_time(philo->m_data->time);
	if (philo->last_meal == -1)
		philo->fatal = true;
	pthread_mutex_unlock(&philo->m_data->eating_lock);
    smart_sleep(philo->m_data->time_to_eat, philo->m_data);
    //usleep(philo->m_data->time_to_eat * 1000);
	print_status(philo, "finished eating");
	philo->meal_counter++;
	pthread_mutex_unlock(philo->right_fork);
	philo->right_fork_locked = 0;
	pthread_mutex_unlock(philo->left_fork);
	philo->left_fork_locked = 0;
}
void philo_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
    smart_sleep(philo->m_data->time_to_sleep, philo->m_data);
	//usleep(philo->m_data->time_to_sleep * 1000);
}
void philo_thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void unlock_all_forks(t_philo *philo)
{
    if (philo->left_fork_locked)
    {
        pthread_mutex_unlock(philo->left_fork);
        philo->left_fork_locked = 0;
    }
    if (philo->right_fork_locked)
    {
        pthread_mutex_unlock(philo->right_fork);
        philo->right_fork_locked = 0;
    }
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(150);
    while (1)
    {
        if (philo->m_data->death_flag == true || philo->m_data->all_full == true || philo->fatal == true)
            return (unlock_all_forks(philo), arg);
        if (philo->is_full == false)
        {
            philo_eating(philo);
            philo_sleeping(philo);
            philo_thinking(philo);
        }
    }
    return (arg);
} 
