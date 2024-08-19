/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/08/19 14:41:39 by juitz            ###   ########.fr       */
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
# include <stdbool.h>

#endif

typedef struct	s_timer
{
	size_t	start_time;
	size_t	current_time;
	size_t	time_passed;
}				t_timer;

typedef struct	s_philo
{
	int id;
	//int	time_to_die;
	//int eat_count;
	//int time_to_eat;
	//int sleep_count;
	//int	time_to_sleep;
	//int	meals;
	int last_meal;
	//int forks;
	//int avail_forks;
	bool death_flag;
	pthread_mutex_t *fork;
	t_timer	time;
}			t_philo;

typedef struct	s_metadata
{
	int	philo_count;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	t_timer	time;
	t_philo	philo;
}				t_metadata;

//philo
int			create_philo(t_metadata *m_data);
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

//timer
size_t	get_current_time(void);
size_t	get_actual_time(t_timer time);

//init
int	mutex_init(t_metadata *m_data);
int	destroy_mutex(t_metadata *m_data);