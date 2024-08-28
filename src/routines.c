/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/08/28 17:36:25 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_eating_even(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork");
    pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken the left fork");
    print_status(philo, "is eating");
	//printf("%d", philo->m_data->time_to_eat);
    usleep(philo->m_data->time_to_eat * 1000);
	philo->m_data->time->time_passed = get_actual_time(philo->m_data->time);
	print_status(philo, "finished eating");
	philo->last_meal = get_actual_time(philo->m_data->time);
	philo->meal_counter++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
    return (NULL);
}

void *philo_eating_uneven(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken the left fork");
    pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork");
    print_status(philo, "is eating");
    usleep(philo->m_data->time_to_eat * 1000);
	philo->m_data->time->time_passed = get_actual_time(philo->m_data->time);
	print_status(philo, "finished eating");
	philo->last_meal = get_actual_time(philo->m_data->time);
	philo->meal_counter++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
    return (NULL);
}
void *philo_sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->m_data->time_to_sleep * 1000);
	return (NULL);
}
void *philo_thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
	return (NULL);
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
	if (philo->id % 2 == 0)
	{
		while (1)
		{
			if (philo->m_data->death_flag == true || philo->m_data->all_full == true)
				return (NULL);
			if (philo->is_full == false)
			{
				philo_eating_even(philo);
				philo_sleeping(philo);
				philo_thinking(philo);
			}
			else if (philo->is_full == true)
			{
				philo_sleeping(philo);
				philo_thinking(philo);
				break ;
			}
		}
	}
	if (philo->id % 2 != 0)
	{
		while (1)
		{
			if (philo->m_data->death_flag == true || philo->m_data->all_full == true)
				return (NULL);
			if (philo->is_full == false)
			{
				philo_eating_uneven(philo);
				philo_sleeping(philo);
				philo_thinking(philo);
			}
			else if (philo->is_full == true && philo->m_data->death_flag == false)
			{
				philo_sleeping(philo);
				philo_thinking(philo);
				break ;
			}
		}
	}
    return (NULL);
}
/* void *routine(void *arg)
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
} */

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