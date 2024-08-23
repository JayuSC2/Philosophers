/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:36:40 by juitz             #+#    #+#             */
/*   Updated: 2024/08/23 12:17:58 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_metadata	m_data, char *status)
{
	pthread_mutex_lock(&m_data.print_lock);
	printf("%d %d %s\n", get_actual_time(m_data.time), m_data.philo->id, status);
	pthread_mutex_unlock(&m_data.print_lock);
}