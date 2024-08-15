/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/15 13:16:14 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *philo)
{
	pthread_t philos[philo->philo_count];
	int i;
	
	i = 1;
	while (i <= philo->philo_count)
	{
		if (pthread_create(&philos[i], NULL, &routine, NULL) != 0)
			printf("Error creating thread\n");
		philo->id = i;
		i++;
	}
	philo->time.start_time = get_current_time();
	i = 0;
    while (i < philo->philo_count)
    {
        pthread_join(philos[i], NULL);
        i++;
    }
    return (0);
}
