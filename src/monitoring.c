/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/08/29 16:27:39 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int monitoring(t_metadata *m_data)
{
    int i;
    int full_count;

    full_count = 0;
    while (1)
    {
        if (m_data->death_flag || m_data->all_full)
        {
            break ;
        }
        i = 0;
        while (i < m_data->philo_count)
        {
            m_data->time->time_passed = get_actual_time(m_data->time);
            if (m_data->time->time_passed - m_data->philo[i].last_meal > m_data->time_to_die)
            {
                m_data->death_flag = true;
				print_status(&m_data->philo[i], "died");
                //printf("%d %d died\n", m_data->time->time_passed, m_data->philo[i].id);
                return (1);
            }
            if (m_data->philo[i].meal_counter == m_data->philo->m_data->num_of_meals && m_data->philo->m_data->num_of_meals != 0)
            {
                if (!m_data->philo[i].is_full)
                {
                    m_data->philo[i].is_full = true;
                    full_count++;
                    printf("%d is full\n", m_data->philo[i].id);
                }
            }
            i++;
        }
        if (full_count == m_data->philo_count)
        {
            m_data->all_full = true;
        }
        usleep(1000);
    }
    return (0);
}
/* 
bool all_philosophers_satiated(t_metadata *m_data)
{
    int i;
    int min_eat_count;
	m_data->all_satiated = false;
	
	min_eat_count = m_data->philo[0].meal_counter;
	i = 1;
    while (i < m_data->philo_count)
    {
        if (m_data->philo[i].meal_counter < min_eat_count)
            return (false);
		i++;
    }
    return (true);
}

void eating_priority(t_philo *philo)
{
    int i;

    philo->m_data->all_satiated = false;
    if (philo->m_data->all_satiated == false)
    {
		if (all_philosophers_satiated(philo->m_data))
			philo->m_data->all_satiated = true;
		philo->can_eat = true;
		pthread_mutex_lock(&philo->m_data->eat_count);
		i = 0;
		while (i < philo->m_data->philo_count)
		{
			if (philo[i].meal_counter < philo->meal_counter)
			{
				philo->can_eat = false;
				break ;
			}
			i++;
		}
		pthread_mutex_unlock(&philo->m_data->eat_count);
	}
} */

/* int	monitoring(t_metadata *m_data)
{
    int i;

    while (1)
    {
        if (m_data->death_flag || m_data->all_full)
        {
            break ;
        }
        i = 0;
        while (i < m_data->philo_count)
        {
            m_data->time->time_passed = get_actual_time(m_data->time);
            if (m_data->time->time_passed - m_data->philo[i].last_meal > m_data->time_to_die && m_data->philo[i].is_full == false)
            {
                m_data->death_flag = true;
                printf("%d %d died\n", m_data->time->time_passed, m_data->philo[i].id);
                return (1);
            }
            if (m_data->philo[i].meal_counter == m_data->philo->m_data->num_of_meals && m_data->philo->m_data->num_of_meals != 0)
            {
                m_data->philo[i].is_full = true;
                printf("%d is full\n", m_data->philo[i].id);
                return (1);
            }
            i++;
        }
        usleep(1000);
    }
	return (0);
} */


/* int	monitoring(t_philo *philo)
{
    int i;

    if (!philo || !philo->m_data || !philo->time) {
        printf("Null pointer detected in monitoring function\n");
        return (1);
    }

    while (1)
    {
        i = 0;
        while (i < philo->m_data->philo_count)
        {
            if (!philo[i].time) {
                printf("Null pointer detected in philo[%d].time\n", i);
                return (1);
            }

            philo->time->current_time = get_actual_time(philo[i].time);
            if (philo->time->current_time - philo[i].last_meal > philo->m_data->time_to_die)
            {
                printf("%d: %d died\n", philo->time->current_time, philo[i].id);
                return (1);
            }
            if (philo[i].eat_count == philo->m_data->num_of_meals && philo->m_data->num_of_meals != 0)
            {
                printf("%d is full", philo[i].id);
                return (1);
            }
            i++;
        }
        usleep(1000);
    }
    return (0);
} */
