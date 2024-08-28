/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:13 by juitz             #+#    #+#             */
/*   Updated: 2024/08/28 13:51:55 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_metadata m_data;

	int	error_check;

	error_check = 0;
    ft_bzero(&m_data, sizeof(t_metadata));
    if (ft_check_args(argc, argv) == 1)
        return (1);
    if (init_variables(&m_data, argc, argv) == 1)
        return (free_metadata(&m_data), 1);
    if (mutex_init(&m_data) == 1)
        return (free_metadata(&m_data), 1);
    init_philos(&m_data);
	error_check = create_philo(&m_data);
    if (create_philo(&m_data) == 1)
		return (free_metadata(&m_data), 1);
	if (create_philo(&m_data) == 2)
		return (free_metadata(&m_data), 1);
    destroy_mutex(&m_data);
	free_metadata(&m_data);
    return (0);
}

