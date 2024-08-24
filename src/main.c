/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/24 14:40:27 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//t_philo	philo;
	t_philo	philo;
	
	ft_bzero(&philo, sizeof(t_philo));
	if (ft_check_args(argc, argv) == 1)
		return (/* free */1);
	if (init_variables(&philo, argc, argv) == 1)
		return (/* free */1);
	mutex_init(&philo);
	printf("test1\n");
/* 	if (philo.m_data->philo_count == 1)
	{
		//create thread with 1 philo
		usleep(philo.m_data->time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	} */
	if (create_philo(&philo) == 1)
		return (printf("Error creating philo\n"), 1);
	destroy_mutex(&philo);
	return (0);
}

