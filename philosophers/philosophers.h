/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:28:23 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 02:10:47 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					num_of_phils;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_meals;
	int					phil_died;
	int					full;
	long int			start_time;
	pthread_mutex_t		lock_print;
	pthread_mutex_t		lock_death;
	pthread_mutex_t		lock_full;
	pthread_mutex_t		lock_eat;
	pthread_t			monitor_thread;
	t_philo				*everyphils;
}						t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			phil_thread;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		lock_meal;
	int					meals_eaten;
	long int			last_meal;
	t_data				*data;
}						t_philo;

int			check_args(char **argv, int argc);
int			ft_atoi(char *nptr);
int			ft_isdigit(int c);
void		init_data(t_data *data, char **argv, int argc);
void		init_phils(t_data *data, t_philo *phils);
void		init_threads(t_data *data, t_philo *phils);
void		init_mutexes(t_data *data, t_philo *phils);
void		init_forks(t_data *data, t_philo *phils);
void		wait_for_threads(t_data *data, t_philo *phils);
void		only_one_phil(t_philo *phil);
void		*eat_sleep_die_repeat(void *args);
int			eat_odd_phils(t_philo *philo);
int			eat_even_phils(t_philo *philo);
void		sleep_think_phil(t_philo *philo);
void		print_phil(t_philo *philo, t_data *data, char *str);
long int	get_time(void);
void		ft_usleep(long int sleep_time, t_data *data);
void		destroy_mutexes(t_data *data, t_philo *phils);
void		*monitoring(void *args);
int			is_phil_dead(t_philo *philo, t_data *data);
void		phil_died(t_philo *philo);
int			are_phils_full(t_philo *phils, t_data *data);
int			end_if(t_philo *philo);

#endif
