/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:30 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 17:31:52 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		ms;

	ms = 0;
	if (gettimeofday(&tv, NULL) != 0)
		return (ft_putendl_fd("gettimeofday failed\n", 2), -1);
	ms = (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec * 0.001;
	return (ms);
}

void	smart_sleep(long long time, t_metadata *m_data)
{
	long long	start_time;
	long long	current_time;

	start_time = get_current_time();
	if (start_time == -1)
		locked_fatal(m_data);
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
		if (start_time == -1)
			locked_fatal(m_data);
		usleep(100);
	}
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
