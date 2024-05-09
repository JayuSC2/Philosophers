/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:30 by juitz             #+#    #+#             */
/*   Updated: 2024/05/09 15:30:52 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	create_IDs(t_philo *philo)
{
	int i;

	i = 1;

	philo->id = malloc(philo->philo_count * sizeof(int));
	while (i <= philo->philo_count)
	{
		philo->id[i] = i;
		i++;
	}
} */

void	create_philo(t_philo *philo)
{
	pthread_t	philo1;
	pthread_t	philo2;
	pthread_t	philo3;
	int i;

	i = 0;
	while (i < philo->philo_count)
	{
		pthread_create(&philo1, NULL, &philo_eating, NULL);
		pthread_create(&philo2, NULL, &philo_sleeping, NULL);
		pthread_create(&philo3, NULL, &philo_thinking, NULL);
		i++;
	}
}