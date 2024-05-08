/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/05/08 16:21:33 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_philo
{
	int philo_count;
	int forks;
	int id;
	int left_fork;
	int right_fork;
	int	time_to_die;
	int eat_count;
	int time_to_eat;
	int sleep_count;
	int	time_to_sleep;
	int think_count;
}			t_philo;

void		create_IDs(t_philo *philo);
void		ft_error(char *str);
long int	ft_atol(const char *str);
int			check_overflow(int argc, char **argv);
int			isnumber(char *str);
void		philo_eating(t_philo *philo);
void		philo_sleeping(t_philo *philo);
void		philo_thinking(t_philo *philo);
