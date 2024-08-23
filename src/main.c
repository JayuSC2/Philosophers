/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/23 16:04:10 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//t_philo	philo;
	t_metadata	m_data;
	
	ft_bzero(&m_data, sizeof(t_metadata));
	if (ft_check_args(argc, argv) == 1)
		return (/* free */1);
	init_variables(&m_data, argc, argv);
	mutex_init(&m_data);
	if (m_data.philo_count == 1)
	{
		//create thread with 1 philo
		usleep(m_data.time_to_die * 1000);
		return (printf("Philo 1 died"), 1);
	}
	if (create_philo(&m_data) == 1)
		return (printf("Error creating philo\n"), 1);
	//destroy_mutex(&m_data);
	return (0);
}

