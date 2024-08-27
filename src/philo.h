/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/08/27 19:10:16 by juitz            ###   ########.fr       */
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
	int	start_time;
	int	current_time;
	int	time_passed;
}				t_timer;

typedef struct	s_philo
{
	typedef struct s_metadata m_data;
	int id;
	int eat_count;
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	int last_meal;
	int	meal_counter;
	bool death_flag;
	bool is_full;
}			t_philo;
typedef struct	s_metadata
{
	int	philo_count;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	pthread_mutex_t *forks;
	pthread_mutex_t	print_lock;
	t_timer	*time;
	t_philo	*philo;
}				t_metadata;


//philo
int			create_philo(t_metadata *m_data);
void		*philo_eating(t_philo philo);
void		*philo_sleeping(t_philo philo);
void		*philo_thinking(t_philo philo);
void		*routine(void *routine);

//utils
void		print_status(t_philo *philo, char *status);
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

//init & destroy
int init_variables(t_metadata *m_data, int argc, char **argv);
int	mutex_init(t_metadata *m_data);
int init_philos(t_metadata *m_data);
int	destroy_mutex(t_metadata *m_data);