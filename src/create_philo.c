/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/22 13:37:31 by julian           ###   ########.fr       */
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
        m_data->philo[i].time = m_data->time;
        if (pthread_create(&threads[i], NULL, &routine, &m_data->philo[i]) != 0)
            printf("Error creating thread\n");
        i++;
    }
    m_data->time->start_time = get_current_time();
	monitoring(m_data);
    i = 0;
    while (i < m_data->philo_count)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    return (0);
}
