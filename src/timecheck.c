/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:30 by juitz             #+#    #+#             */
/*   Updated: 2024/08/15 13:02:39 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval tv;
	size_t	ms;
	
	ms = 0;
	if (gettimeofday(&tv, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		return (ms);
	}
	return (ms = (size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000);
}
size_t	get_actual_time(t_timer timer)
{
	timer.current_time = get_current_time();
	timer.time_passed = (timer.start_time - timer.current_time);
	return (timer.time_passed);
}