/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/08/26 15:12:30 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_eating_even(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	//printf("%d\n", philo->id);
    pthread_mutex_lock(&philo->m_data->forks[philo->id]);
	print_status(philo, "has taken a fork\n");
    pthread_mutex_lock(&philo->m_data->forks[(philo->id + 1) % philo->m_data->philo_count]);
	print_status(philo, "has taken a fork\n");
    print_status(philo, "is eating\n");
	printf("%d", philo->m_data->time_to_eat);
    usleep(philo->m_data->time_to_eat * 1000);
	philo->time->time_passed = get_actual_time(philo->time);
	print_status(philo, "finished eating\n");
	philo->last_meal = get_actual_time(philo->time);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->m_data->forks[(philo->id + 1) % philo->m_data->philo_count]);
	pthread_mutex_unlock(&philo->m_data->forks[philo->id]);
    return (NULL);
}

void *philo_eating_uneven(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	printf("Philo ID: %d\n", philo->id);
    printf("Time to eat: %d\n", philo->m_data->time_to_eat);
    printf("Philo m_data pointer: %p\n", (void *)philo->m_data);
    printf("Philo time pointer: %p\n", (void *)philo->time);
	pthread_mutex_lock(&philo->m_data->forks[(philo->id + 1) % philo->m_data->philo_count]);
	print_status(philo, "has taken a fork\n");
    pthread_mutex_lock(&philo->m_data->forks[philo->id]);
	print_status(philo, "has taken a fork\n");
    print_status(philo, "is eating\n");
	printf("Before usleep\n");
    usleep(philo->m_data->time_to_eat * 1000);
	printf("After usleep\n");
	philo->time->time_passed = get_actual_time(philo->time);
	print_status(philo, "finished eating\n");
	philo->last_meal = get_actual_time(philo->time);
	printf("%d\n", philo->last_meal);
	philo->meal_counter++;
	printf("%d\n", philo->meal_counter);
	pthread_mutex_unlock(&philo->m_data->forks[philo->id]);
	printf("test\n");
	pthread_mutex_unlock(&philo->m_data->forks[(philo->id + 1) % philo->m_data->philo_count]);
	printf("test2\n");
    return (NULL);
}
void *philo_sleeping(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	//philo.sleep_count++;
	print_status(philo, "is sleeping\n");
	usleep(philo->m_data->time_to_sleep * 1000);
	printf("test3\n");
	return (NULL);
}
void *philo_thinking(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	
	print_status(philo, "is thinking\n");
	//usleep(philo.time_to_die * 1000);
	return (NULL);
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
	if (philo->id % 2 == 0)
	{
		while (1)
		{
			usleep(1000);
			philo_eating_even(philo);
			philo_sleeping(philo);
			philo_thinking(philo);
		}
	}
	if (philo->id % 2 != 0)
	{
		while (1)
		{
			philo_eating_uneven(philo);
			philo_sleeping(philo);
			philo_thinking(philo);
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