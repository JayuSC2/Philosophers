/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/05/08 14:36:17 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	
	if (argc != 4 && argc != 5)
		return (ft_error("Error: Incorrect amount of arguments"), 1);
	philo.philo_count = ft_atoi(argv[1]);
	philo.forks = philo.philo_count;
	create_IDs(&philo);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
}
