/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/24 14:45:22 by juitz            ###   ########.fr       */
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
        philo[i].time = philo->time;
		philo[i].last_meal = get_current_time();
		philo[i].eat_count = 0;
        if (pthread_create(&threads[i], NULL, &routine, &philo[i]) != 0)
            return(1);
        i++;
    }
	printf("test2\n");
	//philo->time->start_time = get_current_time();
	//monitoring(philo);
	printf("test3\n");
    i = 0;
	printf("%d\n", philo->m_data->philo_count);
    while (i < philo->m_data->philo_count)
    {
        printf("Joining thread %d\n", i);
        if (pthread_join(threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            return 1;
        }
        printf("Thread %d joined successfully\n", i);
        i++;
    }
    printf("All threads joined\n");
	return (0);
}
