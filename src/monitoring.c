/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:36:27 by juitz             #+#    #+#             */
/*   Updated: 2024/08/27 11:56:13 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_philo *philo)
{
    int i;
	bool	print_flag;
	
	print_flag = false;
	while (1)
	{
		i = 0;
		while (i < philo->m_data->philo_count)
		{
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
}

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
