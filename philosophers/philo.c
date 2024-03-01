/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:39:41 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 02:33:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat_sleep_die_repeat(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!end_if(philo))
			break ;
		if (philo->id % 2 == 0)
		{
			if (!eat_even_phils(philo))
				break ;
		}
		if (philo->id % 2 != 0)
		{
			if (!eat_odd_phils(philo))
				break ;
		}
		sleep_think_phil(philo);
	}
	return (NULL);
}

void	only_one_phil(t_philo *phil)
{
	pthread_mutex_lock(&phil->right_fork);
	print_phil(phil, phil->data, "has taken a fork 🥄");
	ft_usleep(phil->data->time_to_die, phil->data);
	print_phil(phil, phil->data, "died");
	pthread_mutex_unlock(&phil->right_fork);
}

void	wait_for_threads(t_data *data, t_philo *phils)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		if (pthread_join(phils[i].phil_thread, NULL) != 0)
		{
			printf("Error: phils %d thread join failed\n", phils[i].id);
			free(phils);
			destroy_mutexes(data, phils);
			exit(1);
		}
		i++;
	}
	if (pthread_join(data->monitor_thread, NULL) != 0)
	{
		printf("Error: monitor thread join failed\n");
		free(phils);
		destroy_mutexes(data, phils);
		exit(1);
	}
}

void	destroy_mutexes(t_data *data, t_philo *phils)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		pthread_mutex_destroy(&phils[i].right_fork);
		pthread_mutex_destroy(&phils[i].lock_meal);
		i++;
	}
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_death);
	pthread_mutex_destroy(&data->lock_full);
	pthread_mutex_destroy(&data->lock_eat);
}

void	ft_usleep(long int sleep_time, t_data *data)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while (((get_time() - start_time) < sleep_time) && end_if(data->everyphils))
		usleep(1000);
}
