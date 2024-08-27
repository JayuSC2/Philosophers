/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/27 14:44:44 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	int	error_check;
	
	ft_bzero(&philo, sizeof(t_philo));
	if (ft_check_args(argc, argv) == 1)
		return (/* free */1);
	if (init_variables(&philo, argc, argv) == 1)
		return (/* free */1);
	if (mutex_init(philo.m_data) == 1)
		return (/* free */1);
	init_philos(&philo, philo.m_data);
/* 	if (philo.m_data->philo_count == 1)
	{
		//create thread with 1 philo
		usleep(philo.m_data->time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	} */
	error_check = create_philo(&philo);
	if (error_check == 1)
		return (printf("Error creating philo\n"), destroy_mutex(philo.m_data), 1);
	if (error_check == 2)
		return (destroy_mutex(philo.m_data), 1);
	destroy_mutex(philo.m_data);
	return (0);
}

