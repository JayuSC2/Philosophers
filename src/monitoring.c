/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/08/31 12:59:26 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

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
			pthread_mutex_lock(&m_data->time_lock);
            m_data->time->time_passed = get_actual_time(m_data->time);
			pthread_mutex_unlock(&m_data->time_lock);
			if (m_data->time->time_passed == -1)
				return (1);
            if (m_data->time->time_passed - m_data->philo[i].last_meal > m_data->time_to_die)
            {
                m_data->death_flag = true;
				print_status(&m_data->philo[i], "died");
                return (1);
            }
            if (m_data->philo[i].meal_counter == m_data->philo->m_data->num_of_meals && m_data->philo->m_data->num_of_meals != 0)
            {
                if (!m_data->philo[i].is_full)
                {
                    m_data->philo[i].is_full = true;
                    full_count++;
                }
            }
            i++;
        }
        if (full_count == m_data->philo_count)
        {
            m_data->all_full = true;
        }
        //usleep(1000);
    }
    return (0);
}

