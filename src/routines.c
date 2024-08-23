/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/08/23 12:52:50 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_eating(void *arg)
{
	t_metadata m_data = *(t_metadata *)arg;
	
    pthread_mutex_lock(&m_data.philo->fork[m_data.philo->id]);
    pthread_mutex_lock(&m_data.philo->fork[(m_data.philo->id + 1) % m_data.philo_count]);
	//m_data.time->time_passed = get_actual_time(m_data.philo->time);
    print_status(m_data, "is eating\n");
    usleep(m_data.time_to_eat * 1000);
	m_data.time->time_passed = get_actual_time(m_data.philo->time);
	print_status(m_data, "finished eating\n");
	m_data.philo->last_meal = get_actual_time(m_data.philo->time);
	m_data.philo->meal_counter++;
	pthread_mutex_unlock(&m_data.philo->fork[(m_data.philo->id + 1) % m_data.philo_count]);
	pthread_mutex_unlock(&m_data.philo->fork[m_data.philo->id]);
    return (NULL);
}
void *philo_sleeping(void *arg)
{
	t_metadata m_data = *(t_metadata *)arg;
	
	//philo.sleep_count++;
	print_status(m_data, "is sleeping\n");
	usleep(m_data.time_to_sleep * 1000);
	return (NULL);
}
void *philo_thinking(void *arg)
{
	t_metadata m_data = *(t_metadata *)arg;
	
	print_status(m_data, "is thinking\n");
	//usleep(philo.time_to_die * 1000);
	return (NULL);
}
void *routine(void *arg)
{
	t_metadata m_data = *(t_metadata *)arg;

	if (m_data.philo_count > 2 && m_data.philo_count % 2 == 0)
	{
		if (m_data.philo->id % 2 == 0)
		{
			philo_eating(&m_data);
			philo_sleeping(&m_data);
			philo_thinking(&m_data);
		}
		if (m_data.philo->id % 2 == 1)
		{
			philo_sleeping(&m_data);
			philo_thinking(&m_data);
			philo_eating(&m_data);
		}
	}
	return (NULL);
}

/* void *philo_eating(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    pthread_mutex_lock(&philo->fork[philo->id]);
    pthread_mutex_lock(&philo->fork[(philo->id + 1) % philo->philo_count]);

    philo->time->time_passed = get_actual_time(*philo->time);
    printf("%zu: Philo %d is eating\n", philo->time->time_passed, philo->id);
    usleep(philo->time_to_eat * 1000);
    philo->time->time_passed = get_actual_time(*philo->time);
    printf("%zu: Philo %d has finished eating\n", philo->time->time_passed, philo->id);
    philo->last_meal = get_actual_time(*philo->time);

    pthread_mutex_unlock(&philo->fork[(philo->id + 1) % philo->philo_count]);
    pthread_mutex_unlock(&philo->fork[philo->id]);

    return (NULL);
}

void *philo_sleeping(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    printf("Philo %d is sleeping\n", philo->id);
    usleep(philo->time_to_sleep * 1000);
    return (NULL);
}

void *philo_thinking(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    printf("Philo %d is thinking\n", philo->id);
    return (NULL);
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->philo_count > 2 && philo->philo_count % 2 == 0)
    {
        if (philo->id % 2 == 0)
        {
            philo_eating(philo);
            philo_sleeping(philo);
            philo_thinking(philo);
        }
        if (philo->id % 2 == 1)
        {
            philo_sleeping(philo);
            philo_thinking(philo);
            philo_eating(philo);
        }
    }
    return (NULL);
} */