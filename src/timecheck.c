/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:30 by juitz             #+#    #+#             */
/*   Updated: 2024/09/02 15:52:14 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_current_time(void)
{
	struct timeval	tv;
	int				ms;

	ms = 0;
	if (gettimeofday(&tv, NULL) != 0)
		return (ft_putendl_fd("gettimeofday failed\n", 2), -1);
	ms = (int)tv.tv_sec * 1000 + (int)tv.tv_usec / 1000;
	return (ms);
}

// int	get_actual_time(t_timer *timer)
// {
// 	int	time_passed;
// 	int	current_time;

// 	//pthread_mutex_lock(&timer->time_lock);
// 	current_time = get_current_time();
// 	if (current_time == -1)
// 	{
// 		//pthread_mutex_unlock(&timer->time_lock);
// 		return (-1);
// 	}
// 	time_passed = timer->current_time - timer->start_time;
// 	timer->time_passed = time_passed;
// 	//pthread_mutex_unlock(&timer->time_lock);
// 	return (time_passed);
// }

void	smart_sleep(int time, t_metadata *m_data)
{
	int	start_time;
	int	current_time;

	start_time = get_current_time();
	current_time = start_time;
	while (current_time - start_time < time)
	{
		pthread_mutex_lock(&m_data->death_lock);
		if (m_data->death_flag)
		{
			pthread_mutex_unlock(&m_data->death_lock);
			break ;
		}
		pthread_mutex_unlock(&m_data->death_lock);
		current_time = get_current_time();
		usleep(100);
	}
}
