/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/09/01 19:19:40 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_metadata	m_data;
	int			error_check;

	error_check = 0;
	ft_bzero(&m_data, sizeof(t_metadata));
	if (ft_check_args(argc, argv) == 1)
		return (1);
	if (init_m_data(&m_data, argc, argv) == 1)
		return (free_all(&m_data), 1);
	if (mutex_init(&m_data) == 1)
		return (free_all(&m_data), 1);
	if (init_philos(&m_data) == 1)
		return (free_all(&m_data), 1);
	error_check = create_philo(&m_data);
	if ((error_check) == 1 || ((error_check) == 2))
		return (free_all(&m_data), 1);
	destroy_mutex(&m_data);
	free_all(&m_data);
	return (0);
}
