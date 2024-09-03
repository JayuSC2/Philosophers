/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:09:52 by juitz             #+#    #+#             */
/*   Updated: 2024/09/03 17:31:03 by juitz            ###   ########.fr       */
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

/* typedef struct s_timer
{
	int				start_time;
	int				current_time;
	int				time_passed;
	pthread_mutex_t	time_lock;
}				t_timer;
 */
typedef struct s_philo
{
	struct s_metadata	*m_data;
	int					id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					left_fork_locked;
	int					right_fork_locked;
	int					last_meal;
	int					meal_counter;
	bool				is_full;
	bool				fatal;
}			t_philo;
typedef struct s_metadata
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	bool			death_flag;
	bool			all_full;
	pthread_mutex_t	all_full_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	int				start_time;
	t_philo			*philo;
}				t_metadata;

int			create_philo(t_metadata *m_data);
void		philo_eating(t_philo *philo);
void		philo_sleeping(t_philo *philo);
void		philo_thinking(t_philo *philo);
void		*routine(void *routine);
void		one_philo(t_philo *philo);

int			print_status(t_philo *philo, char *status);
void		locked_fatal(t_metadata *m_data);
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_error(char *str);
long int	ft_atol(const char *str);
int			check_overflow(int argc, char **argv);
int			isnumber(char *str);
int			ft_atoi(const char *str);

int			ft_check_args(int argc, char **argv);

int			monitoring(t_metadata *m_data);

long long	get_current_time(void);
void		smart_sleep(long long time, t_metadata *m_data);

int			init_m_data(t_metadata *m_data, int argc, char **argv);
int			init_mutex(t_metadata *m_data);
int			init_philos(t_metadata *m_data);
int			destroy_mutex(t_metadata *m_data);
void		free_all(t_metadata *m_data);

#endif