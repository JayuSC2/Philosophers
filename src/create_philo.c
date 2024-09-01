/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/09/01 16:35:47 by juitz            ###   ########.fr       */
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
        if (pthread_create(&threads[i], NULL, &routine, &m_data->philo[i]) != 0)
			return (ft_putendl_fd("Error creating thread",2), 1);
        i++;
    }
	//philo->time->start_time = get_current_time();
	/* if (monitoring(m_data) == 1)
		return (2); */
	monitoring(m_data);
    i = 0;
    while (i < m_data->philo_count)
    {
        if (pthread_join(threads[i], NULL) != 0)
            return (ft_putendl_fd("Error joining thread",2), 1);
        i++;
    }
	return (0);
}

