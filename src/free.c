/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:39:16 by juitz             #+#    #+#             */
/*   Updated: 2024/08/30 15:18:43 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_all(t_metadata *m_data)
{
    if (m_data->philo != NULL)
        free(m_data->philo);
    if (m_data->time != NULL)
        free(m_data->time);
    if (m_data->forks != NULL)
    	free(m_data->forks);
}