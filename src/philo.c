/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/05/08 16:25:13 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_IDs(t_philo *philo)
{
	int i;

	i = 1;

	philo->id = malloc(philo->philo_count * sizeof(int));
	while (i <= philo->philo_count)
	{
		philo->id[i] = i;
		i++;
	}
}

void	create_philo(t_philo *philo)
{
	pthread_t	philos;
	int i;
	int j;

	i = 0;
	while (i < philo->philo_count)
	{
		pthread_create(philo[j], NULL, &philo_eating, philo->time_to_eat);
		pthread_create(philo->id++, NULL, &philo_sleeping);
		
	}
}