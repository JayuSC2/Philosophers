/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:51 by juitz             #+#    #+#             */
/*   Updated: 2024/05/08 16:34:26 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void philo_eating(t_philo *philo)
{
	philo->eat_count++;
	printf("Philo %d is eating\n", philo->id);
	sleep(philo->time_to_eat);
}
void philo_sleeping(t_philo *philo)
{
	philo->sleep_count++;
	printf("Philo %d is sleeping\n", philo->id);
	sleep(philo->time_to_sleep);
}
void philo_thinking(t_philo *philo)
{
	philo->think_count++;
	printf("Philo %d is thinking\n", philo->id);
	sleep(philo->time_to_die);
}