/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/19 14:38:26 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_metadata *m_data)
{
	pthread_t philos[m_data->philo_count];
	int i;
	
	i = 1;
	while (i <= m_data->philo_count)
	{
		if (pthread_create(&philos[i], NULL, &routine, NULL) != 0)
			printf("Error creating thread\n");
		m_data->philo.id = i;
		i++;
	}
	m_data->time.start_time = get_current_time();
	i = 0;
    while (i < m_data->philo_count)
    {
        pthread_join(philos[i], NULL);
        i++;
    }
    return (0);
}
