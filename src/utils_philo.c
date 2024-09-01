/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:51:17 by juitz             #+#    #+#             */
/*   Updated: 2024/09/01 17:53:41 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, char *status)
{
	int actual_time;

	pthread_mutex_lock(&philo->m_data->print_lock);
	actual_time = get_actual_time(philo->m_data->time);
	if (actual_time == -1)
		philo->fatal = true;
	printf("%d %d %s\n", actual_time, philo->id, status);
	pthread_mutex_unlock(&philo->m_data->print_lock);
	return (0);
}
void one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork");
	smart_sleep(philo->m_data->time_to_eat, philo->m_data);
	pthread_mutex_unlock(philo->right_fork);
}