/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/08/23 12:57:35 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_metadata *m_data)
{
    int i;

	while (1)
	{
		i = 0;
		while (i < m_data->philo_count)
		{
			m_data->time->current_time = get_actual_time(m_data->philo[i].time);
			if (m_data->time->current_time - m_data->philo[i].last_meal > m_data->time_to_die)
			{
				printf("%d: %d died\n", m_data->time->current_time, m_data->philo[i].id);
				return (1);
			}
			if (m_data->philo[i].eat_count == m_data->num_of_meals && m_data->num_of_meals != 0)
			{
				printf("%d is full", m_data->philo[i].id);
				return (1);
			}
			i++;
		}
		usleep(1000);
	}
	return (0);
}
