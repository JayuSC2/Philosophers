/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:39:16 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 16:56:21 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_metadata *m_data)
{
	if (m_data->philo != NULL)
		free(m_data->philo);
	if (m_data->time != NULL)
		free(m_data->time);
	if (m_data->forks != NULL)
		free(m_data->forks);
}

int	destroy_mutex(t_metadata *m_data)
{
	int	i;

	i = 0;
	while (i < m_data->philo_count)
	{
		if (pthread_mutex_destroy(&m_data->forks[i]) != 0)
			ft_putendl_fd("Error destroying fork_mutex\n", 2);
		i++;
	}
	if (pthread_mutex_destroy(&m_data->print_lock) != 0
		|| pthread_mutex_destroy(&m_data->death_lock) != 0
		|| pthread_mutex_destroy(&m_data->meal_lock) != 0
		|| pthread_mutex_destroy(&m_data->time->time_lock) != 0)
		ft_putendl_fd("Error destroying mutex", 2);
	return (0);
}
