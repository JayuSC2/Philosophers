/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/27 13:51:27 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *philo)
{
    pthread_t threads[philo->m_data->philo_count];
    int i;
    
    i = 0;
    while (i < philo->m_data->philo_count)
    {
        philo[i].id = i + 1;
        philo[i].timer = philo->timer;
		philo[i].last_meal = get_actual_time(philo->timer);
		philo[i].eat_count = 0;
        if (pthread_create(&threads[i], NULL, &routine, &philo[i]) != 0)
		{
			printf("Error creating thread %d\n", i);
            return(1);
		}
        i++;
    }
	//philo->time->start_time = get_current_time();
	if (monitoring(philo) == 1)
		return (2);
    i = 0;
    while (i < philo->m_data->philo_count)
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
