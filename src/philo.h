/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/08/23 12:06:29 by juitz            ###   ########.fr       */
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

/* typedef struct	s_timer
{
    int	start_time;
    int	current_time;
    int	time_passed;
}				t_timer;

typedef struct	s_metadata
{
    int	philo_count;
    int	time_to_die;
    int time_to_eat;
    int time_to_sleep;
}				t_metadata;

typedef struct	s_philo
{
    int id;
    int last_meal;
    bool death_flag;
    pthread_mutex_t *fork;
    t_timer	*time;
    s_metadata *metadata;
}			t_philo; */

typedef struct	s_timer
{
	int	start_time;
	int	current_time;
	int	time_passed;
}				t_timer;

typedef struct	s_philo
{
	int id;
	//int	time_to_die;
	int eat_count;
	//int time_to_eat;
	//int sleep_count;
	//int	time_to_sleep;
	//int	meals;
	pthread_mutex_t *fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int last_meal;
	int	meal_counter;
	//int forks;
	//int avail_forks;
	bool death_flag;
	t_timer	*time;
}			t_philo;

typedef struct	s_metadata
{
	int	philo_count;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	//pthread_mutex_t *forks;
	pthread_mutex_t	print_lock;
	t_timer	*time;
	t_philo	*philo;
}				t_metadata;

//philo
int			create_philo(t_metadata *m_data);
void		create_IDs(t_philo *philo);
void		*philo_eating(void *eating);
void		*philo_sleeping(void *sleeping);
void		*philo_thinking(void *thinking);
void		*routine(void *routine);

//utils
void		print_status(t_metadata	m_data, char *status);
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
int	monitoring(t_metadata *m_data);

//timer
int	get_current_time(void);
int	get_actual_time(t_timer *timer);

//init
int	init_variables(t_metadata *m_data,
int argc, char **argv);
int	mutex_init(t_metadata *m_data);
int	destroy_mutex(t_metadata *m_data);