/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/08/20 20:59:32 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_metadata *m_data)
{
    int i;
    size_t current_time;

	while (1)
	{
		i = 0;
		while (i < m_data->philo_count)
		{
			current_time = get_actual_time(*(m_data->philo[i].time));
			if (current_time - m_data->philo[i].last_meal > m_data->time_to_die)
			{
				printf("%zu: Philo %d died\n", current_time, m_data->philo[i].id);
				return (1);
			}
			i++;
		}
		usleep(1000);
	}
	return (0);
}