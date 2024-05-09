/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/05/09 16:49:20 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *philo_eating(void *eating)
{
	t_philo *philo;
	pthread_mutex_t lock;
	
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_lock(&lock);
	philo->eat_count++;
	philo->avail_forks -= 2;
	printf("Philo %d is eating\n", philo->id);
	sleep(philo->time_to_eat);
	pthread_mutex_unlock(&lock);
}
void *philo_sleeping(void *sleeping)
{
	t_philo *philo;
	
	philo->sleep_count++;
	printf("Philo %d is sleeping\n", philo->id);
	sleep(philo->time_to_sleep);
}
void *philo_thinking(void *thinking)
{
	t_philo *philo;
	
	philo->think_count++;
	printf("Philo %d is thinking\n", philo->id);
	sleep(philo->time_to_die);
}