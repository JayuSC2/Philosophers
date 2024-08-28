/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:45:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/28 17:12:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_variables(t_metadata *m_data, int argc, char **argv)
{	
    m_data->philo_count = ft_atoi(argv[1]);
    m_data->time_to_die = ft_atoi(argv[2]);
    m_data->time_to_eat = ft_atoi(argv[3]);
    m_data->time_to_sleep = ft_atoi(argv[4]);
	m_data->death_flag = false;
	m_data->all_full = false;
    if (argc == 6)
        m_data->num_of_meals = ft_atoi(argv[5]);
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

int mutex_init(t_metadata *m_data)
{
    if (forks_init(m_data) == 1)
        return (1);
    if (print_init(m_data) == 1)
        return (1);
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
        //m_data->philo[i].m_data = m_data;
		m_data->philo[i].last_meal = get_actual_time(m_data->time);
		m_data->philo[i].meal_counter = 0;
		m_data->philo[i].m_data = m_data;
        i++;
    }
    return 0;
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
    free(m_data->forks);
    return (0);
}


