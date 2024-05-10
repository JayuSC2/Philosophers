/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/05/10 16:51:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_philo
{
	int philo_count;
	int	avail_forks;
	int id;
	// int left_fork;
	// int right_fork;
	int	time_to_die;
	int eat_count;
	int time_to_eat;
	int sleep_count;
	int	time_to_sleep;
	int think_count;
	pthread_t	forks;
	pthread_mutex_t lock;
}			t_philo;

void		create_philo(t_philo *philo);
void		create_IDs(t_philo *philo);

//utils
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_error(char *str);
long int	ft_atol(const char *str);
int			check_overflow(int argc, char **argv);
int			isnumber(char *str);
int			ft_atoi(const char *str);


void		*philo_eating(void *eating);
void		*philo_sleeping(void *sleeping);
void		*philo_thinking(void *thinking);
