/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/05/10 18:31:20 by juitz            ###   ########.fr       */
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
	pthread_mutex_init(&philo->lock, NULL);
	pthread_mutex_lock(&philo->lock);
	philo->eat_count++;
	philo->avail_forks -= 2;
	printf("Philo %d is eating\n", philo->id);
	usleep(philo->time_to_eat);
	philo->avail_forks += 2;
	pthread_mutex_unlock(&philo->lock);
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