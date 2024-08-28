/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/28 13:51:50 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_metadata *m_data)
{
    pthread_t threads[m_data->philo_count];
    int i;
    
    i = 0;
    while (i < m_data->philo_count)
    {
        m_data->philo[i].id = i + 1;
        //m_data->philo[i].time = philo->time;
		m_data->philo[i].last_meal = get_actual_time(m_data->time);
		m_data->philo[i].eat_count = 0;
        if (pthread_create(&threads[i], NULL, &routine, &m_data->philo[i]) != 0)
		{
			printf("Error creating thread %d\n", i);
            return(1);
		}
        i++;
    }
	//philo->time->start_time = get_current_time();
	if (monitoring(m_data) == 1)
		return (2);
    i = 0;
    while (i < m_data->philo_count)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            return (1);
        }
        i++;
    }
	return (0);
}
