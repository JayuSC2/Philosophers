/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/30 18:59:08 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_current_time(void)
{
	struct timeval tv;
	int	ms;
	
	ms = 0;
	if (gettimeofday(&tv, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		return (-1);
	}
	ms = (int)tv.tv_sec * 1000 + (int)tv.tv_usec / 1000;
    return (ms);
}
int	get_actual_time(t_timer *timer)
{
	timer->current_time = get_current_time();
	if (timer->current_time == -1)
		return (-1);
	timer->time_passed = (timer->current_time - timer->start_time);
	return (timer->time_passed);
}
void smart_sleep(int time, t_metadata *m_data)
{
    int start_time;
    int current_time;

    start_time = get_actual_time(m_data->time);
    current_time = start_time;
    while (current_time - start_time < time)
    {
        if (m_data->death_flag)
        {
            break;
        }
        current_time = get_actual_time(m_data->time);
        usleep(100);
    }
}