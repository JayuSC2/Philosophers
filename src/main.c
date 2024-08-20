/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/20 20:00:52 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/types/struct_timeval.h>

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_metadata	m_data;
	
	ft_bzero(&m_data, sizeof(t_metadata));
	ft_bzero(&philo, sizeof(t_philo));
	mutex_init(&m_data);
	if (ft_check_args(argc, argv) == 1)
		return (printf("Error: Invalid arguments\n"), 1);
	m_data.philo_count = ft_atoi(argv[1]);
	if (m_data.philo_count == 1)
	{
		//create thread with 1 philo
		usleep(m_data.time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	}
	m_data.time_to_die = ft_atoi(argv[2]);
	m_data.time_to_eat = ft_atoi(argv[3]);
	m_data.time_to_sleep = ft_atoi(argv[4]);
	if (create_philo(&m_data) == 1)
		return (printf("Error creating philo\n"), 1);
	destroy_mutex(&m_data);
	return (0);
}
