/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/31 15:48:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int init_m_data(t_metadata *m_data, int argc, char **argv)
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
			return (printf("Error: num_of_meals can't be 0\n"), 1);
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

int init_philos(t_metadata *m_data)
{
    int i;

    i = 0;
    while (i < m_data->philo_count)
    {
        m_data->philo[i].id = i + 1;
        m_data->philo[i].left_fork = &m_data->forks[i];
        m_data->philo[i].right_fork = &m_data->forks[(i + 1) % m_data->philo_count];
		m_data->philo[i].is_full = false;
		m_data->philo[i].fatal = false;
		m_data->philo[i].last_meal = get_actual_time(m_data->time);
		if (m_data->philo[i].last_meal == -1)
			return (1);
		m_data->philo[i].meal_counter = 0;
		m_data->philo[i].m_data = m_data;
        i++;
    }
    return 0;
}

int forks_init(t_metadata *m_data)
{
    int i;

    m_data->forks = malloc(sizeof(pthread_mutex_t) * m_data->philo_count);
    if (m_data->forks == NULL)
    {
        printf("Error allocating memory");
        return (1);
    }
    i = 0;
    while (i < m_data->philo_count)
    {
        if (pthread_mutex_init(&m_data->forks[i], NULL) != 0)
        {
            destroy_mutex(m_data);
            printf("Error initializing mutex\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int death_flag_init(t_metadata *m_data)
{
    if (pthread_mutex_init(&m_data->death_lock, NULL) != 0)
    {
        destroy_mutex(m_data);
        printf("Error initializing eating mutex\n");
        return (1);
    }
    return (0);
}

int print_init(t_metadata *m_data)
{
    if (pthread_mutex_init(&m_data->print_lock, NULL) != 0)
    {
        destroy_mutex(m_data);
        printf("Error initializing print mutex\n");
        return (1);
    }
    return (0);
}

int time_init(t_metadata *m_data)
{
	if (pthread_mutex_init(&m_data->time->time_lock, NULL) != 0)
	{
		destroy_mutex(m_data);
		printf("Error initializing time mutex\n");
		return (1);
	}
	return (0);
}
int all_full_init(t_metadata *m_data)
{
	if (pthread_mutex_init(&m_data->all_full_lock, NULL) != 0)
	{
		destroy_mutex(m_data);
		printf("Error initializing all_full mutex\n");
		return (1);
	}
	return (0);
}

int mutex_init(t_metadata *m_data)
{
    if (forks_init(m_data) == 1)
        return (1);
    if (print_init(m_data) == 1)
		return (1);
	if (death_flag_init(m_data) == 1)
		return (1);
	if (time_init(m_data) == 1)
		return (1);
/* 	if (all_full_init(m_data) == 1)
		return (1); */
    return (0);
}

int destroy_mutex(t_metadata *m_data)
{
    int i;

    i = 0;
    while (i < m_data->philo_count)
    {
        if (pthread_mutex_destroy(&m_data->forks[i]) != 0)
        {
            printf("Error destroying fork_mutex\n");
            return (1);
        }
        i++;
    }
    if (pthread_mutex_destroy(&m_data->print_lock) != 0)
    {
        printf("Error destroying print_mutex\n");
        return (1);
    }
	if (pthread_mutex_destroy(&m_data->death_lock) != 0)
	{
		 printf("Error destroying eating_mutex\n");
		 return (1);
	}
	if (pthread_mutex_destroy(&m_data->time->time_lock) != 0)
	{
		 printf("Error destroying eating_mutex\n");
		 return (1);
	}
/* 	if (pthread_mutex_destroy(&m_data->all_full_lock) != 0)
	{
		 printf("Error destroying eating_mutex\n");
		 return (1);
	} */
/* 	if (pthread_mutex_destroy(&m_data->time_lock) != 0)
	{
		 printf("Error destroying eating_mutex\n");
		 return (1);
	} */
	return (0);
}
