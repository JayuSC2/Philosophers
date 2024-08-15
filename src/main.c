/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/15 13:12:45 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/types/struct_timeval.h>

int	main(int argc, char **argv)
{
	t_philo	philo;
	
	ft_bzero(&philo, sizeof(t_philo));
	mutex_init(&philo);
	if (ft_check_args(argc, argv) == 1)
		return (printf("Error: Invalid arguments\n"), 1);
	philo.philo_count = ft_atoi(argv[1]);
	if (philo.philo_count == 1)
	{
		usleep(philo.time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	}
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (create_philo(&philo) == 1)
		return (printf("Error creating philo\n"), 1);
	destroy_mutex(&philo);
	return (0);
}
