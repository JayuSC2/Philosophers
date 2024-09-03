/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 17:00:57 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_metadata	m_data;

	ft_bzero(&m_data, sizeof(t_metadata));
	if (ft_check_args(argc, argv) == 1)
		return (1);
	if (init_m_data(&m_data, argc, argv) == 1)
		return (free_all(&m_data), 1);
	if (init_mutex(&m_data) == 1)
		return (ft_putendl_fd("Error creating mutex", 2), free_all(&m_data), 1);
	if (init_philos(&m_data) == 1)
		return (free_all(&m_data), 1);
	if (create_philo(&m_data) == 1)
		return (destroy_mutex(&m_data), free_all(&m_data), 1);
	free_all(&m_data);
	return (0);
}
