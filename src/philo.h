/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/07/30 17:02:32 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define _DEFAULT_SOURCE
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <bits/types/struct_timeval.h>

#endif

typedef struct	s_philo
{
	int philo_count;
	int id;
	// int left_fork;
	// int right_fork;
	int	time_to_die;
	int eat_count;
	int time_to_eat;
	int sleep_count;
	int	time_to_sleep;
	int think_count;
	int	meals;
	int last_meal;
	int forks;
	int avail_forks;
	long long	start;
	long long	timer;
	pthread_mutex_t lock;
}			t_philo;

//philo
void		create_philo(t_philo *philo);
void		create_IDs(t_philo *philo);
void		*philo_eating(void *eating);
void		*philo_sleeping(void *sleeping);
void		*philo_thinking(void *thinking);
void		*routine(void *routine);

//utils
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_error(char *str);
long int	ft_atol(const char *str);
int			check_overflow(int argc, char **argv);
int			isnumber(char *str);
int			ft_atoi(const char *str);

//error_checks
int	ft_check_args(int argc, char **argv);

//monitoring
long long	gettime(struct timeval);