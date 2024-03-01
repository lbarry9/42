/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:15:35 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 02:01:28 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	phil_died(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->lock_death);
	data->phil_died = 1;
	pthread_mutex_lock(&data->lock_print);
	printf("%ld %d died\n", (get_time() - data->start_time), philo->id);
	pthread_mutex_unlock(&data->lock_print);
	pthread_mutex_unlock(&data->lock_death);
}

int	is_phil_dead(t_philo *phils, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		pthread_mutex_lock(&phils[i].lock_meal);
		if ((get_time() - phils[i].last_meal) > data->time_to_die)
		{
			pthread_mutex_unlock(&phils[i].lock_meal);
			phil_died(&phils[i]);
			return (1);
		}
		pthread_mutex_unlock(&phils[i].lock_meal);
		i++;
	}
	return (0);
}

int	are_phils_full(t_philo *phils, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		pthread_mutex_lock(&phils[i].lock_meal);
		if (phils[i].meals_eaten < data->num_of_meals)
		{
			pthread_mutex_unlock(&phils[i].lock_meal);
			return (0);
		}
		pthread_mutex_unlock(&phils[i].lock_meal);
		i++;
	}
	pthread_mutex_lock(&data->lock_full);
	data->full = 1;
	pthread_mutex_unlock(&data->lock_full);
	return (1);
}

int	end_if(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock_death);
	if (philo->data->phil_died == 1)
		return (pthread_mutex_unlock(&philo->data->lock_death), 0);
	pthread_mutex_unlock(&philo->data->lock_death);
	pthread_mutex_lock(&philo->data->lock_full);
	if (philo->data->num_of_meals != -1 && philo->data->full == 1)
		return (pthread_mutex_unlock(&philo->data->lock_full), 0);
	pthread_mutex_unlock(&philo->data->lock_full);
	return (1);
}

void	*monitoring(void *args)
{
	t_philo	*allmyphils;
	t_data	*data;

	data = (t_data *)args;
	allmyphils = data->everyphils;
	while (1)
	{
		if (data->phil_died)
			return (NULL);
		if (is_phil_dead(allmyphils, data))
			return (NULL);
		if (data->num_of_meals != -1)
		{
			if (are_phils_full(allmyphils, data))
				return (NULL);
		}
	}
	return (NULL);
}
