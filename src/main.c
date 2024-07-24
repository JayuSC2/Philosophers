/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/07/24 18:22:54 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	int	i;
	int j;

	i = 1;
	j = 0;
	ft_bzero(&philo, sizeof(t_philo));
	if (ft_check_args(argc, argv) == 1)
		return (printf("Error: Invalid arguments\n"), 1);
	philo.philo_count = ft_atoi(argv[1]);
	if (philo.philo_count == 1)
	{
		usleep(philo.time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	}
	philo.forks = philo.philo_count;
	//create_IDs(&philo);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	create_philo(&philo);
}
