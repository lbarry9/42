/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:07:16 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 02:11:46 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, char **argv, int argc)
{
	data->num_of_phils = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
	else
		data->num_of_meals = -1;
	data->phil_died = 0;
	data->full = 0;
	data->start_time = get_time();
}

void	init_phils(t_data *data, t_philo *phils)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		phils[i].id = i + 1;
		phils[i].data = data;
		phils[i].meals_eaten = 0;
		phils[i].last_meal = get_time();
		i++;
	}
}

void	init_forks(t_data *data, t_philo *phils)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		if (pthread_mutex_init(&phils[i].right_fork, NULL))
		{
			printf("Error: mutex init failed\n");
			free(phils);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->num_of_phils)
	{
		if (i == data->num_of_phils - 1)
			phils[i].left_fork = &(phils[0].right_fork);
		else
			phils[i].left_fork = &(phils[i + 1].right_fork);
		i++;
	}
}

void	init_mutexes(t_data *data, t_philo *phils)
{
	int	i;

	init_forks(data, phils);
	i = 0;
	while (i < data->num_of_phils)
	{
		if (pthread_mutex_init(&phils[i].lock_meal, NULL))
		{
			printf("Error: mutex init failed\n");
			free(phils);
			exit(1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->lock_print, NULL)
		|| pthread_mutex_init(&data->lock_full, NULL)
		|| pthread_mutex_init(&data->lock_eat, NULL)
		|| pthread_mutex_init(&data->lock_death, NULL))
	{
		printf("Error: mutex init failed\n");
		free(phils);
		exit(1);
	}
}

void	init_threads(t_data *data, t_philo *phils)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		if (pthread_create(&phils[i].phil_thread,
				NULL, &eat_sleep_die_repeat, &phils[i]) != 0)
		{
			printf("Error: phils %d thread creation failed\n", phils[i].id);
			destroy_mutexes(data, phils);
			free(phils);
			exit(1);
		}
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, &monitoring, data) != 0)
	{
		printf("Error: monitor thread creation failed\n");
		free (phils);
		destroy_mutexes(data, phils);
		exit(1);
	}
}
