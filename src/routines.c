/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/08/16 09:33:55 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_eating(void *eating)
{
	t_philo *philo;
	
	(void) eating;
    pthread_mutex_lock(&philo->fork[philo->id]);
    pthread_mutex_lock(&philo->fork[(philo->id + 1) % philo->philo_count]);

    philo->eat_count++;
    philo->avail_forks -= 2;
	philo->time.time_passed = get_actual_time(philo->time);
    printf("%zu: Philo %d is eating\n", philo->time.time_passed, philo->id);
    usleep(philo->time_to_eat * 1000);
    philo->avail_forks += 2;

    pthread_mutex_unlock(&philo->fork[(philo->id + 1) % philo->philo_count]);
    pthread_mutex_unlock(&philo->fork[philo->id]);

    return NULL;
}
void *philo_sleeping(void *sleeping)
{
	t_philo *philo;
	(void) sleeping;
	
	philo->sleep_count++;
	printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
	return (NULL);
}
void *philo_thinking(void *thinking)
{
	t_philo *philo;
	
	(void) thinking;
	philo->think_count++;
	printf("Philo %d is thinking\n", philo->id);
	//usleep(philo->time_to_die * 1000);
	return (NULL);
}
void *routine(void *routine)
{
	t_philo *philo;

	ft_bzero(&philo, sizeof(t_philo));
	(void) routine;
	if (philo->philo_count > 2)
	{
		if (philo->id % 2 == 0)
		{
			philo_eating(&philo);
			philo_sleeping(&philo);
			philo_thinking(&philo);
		}
		if (philo->id % 2 == 1)
		{
			philo_sleeping(&philo);
			philo_thinking(&philo);
			philo_eating(&philo);
		}
	}
	return (NULL);
}