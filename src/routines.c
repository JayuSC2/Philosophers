/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/07/15 16:47:40 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *philo_eating(void *eating)
{
	t_philo *philo;
	(void) eating;
	
	ft_bzero(&philo, sizeof(t_philo));
	/* if (philo->avail_forks < 2)
		return (1); */
	if (pthread_mutex_init(&philo->lock, NULL) != 0)
		printf("Error initializing mutex");
	if (pthread_mutex_lock(&philo->lock) != 0)
		printf("Error creating mutex lock");
	philo->eat_count++;
	philo->avail_forks -= 2;
	if (philo->avail_forks < 2)
		printf("Error: not enough forks\n");
	printf("Philo %d is eating\n", philo->id);
	usleep(philo->time_to_eat);
	philo->avail_forks += 2;
	if (pthread_mutex_unlock(&philo->lock) != 0)
		printf("Error unlocking mutex\n");
	return (NULL);
}
void *philo_sleeping(void *sleeping)
{
	t_philo *philo;
	(void) sleeping;
	
	ft_bzero(&philo, sizeof(t_philo));
	philo->sleep_count++;
	printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->time_to_sleep);
	return (NULL);
}
void *philo_thinking(void *thinking)
{
	t_philo *philo;
	
	ft_bzero(&philo, sizeof(t_philo));
	(void) thinking;
	philo->think_count++;
	printf("Philo %d is thinking\n", philo->id);
	usleep(philo->time_to_die);
	return (NULL);
}
void *routine(void *routine)
{
	t_philo *philo;

	(void) routine;
	if (philo->philo_count > 2)
	{
		if (philo->id % 3 == 0)
		//eat;
		//usleep time_to_eat;
		if (philo->id % 3 == 1)
		//sleep;
		//usleep time_to_sleep;
		if (philo->id % 3 == 2)
		//think;
		//usleep ????
	}
}