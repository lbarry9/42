/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:35:28 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 02:01:55 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_phil(t_philo *philo, t_data *data, char *str)
{
	if (!end_if(philo))
		return ;
	pthread_mutex_lock(&data->lock_print);
	printf("%ld %d %s\n", (get_time() - data->start_time), philo->id, str);
	pthread_mutex_unlock(&data->lock_print);
}

int	eat_odd_phils(t_philo *philo)
{
	if (!end_if(philo))
		return (0);
	pthread_mutex_lock(philo->left_fork);
	print_phil(philo, philo->data, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork);
	print_phil(philo, philo->data, "has taken a fork");
	print_phil(philo, philo->data, "is eating");
	pthread_mutex_lock(&philo->data->lock_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->lock_eat);
	pthread_mutex_lock(&philo->lock_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->lock_meal);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
	return (1);
}

int	eat_even_phils(t_philo *philo)
{
	if (!end_if(philo))
		return (0);
	pthread_mutex_lock(&philo->right_fork);
	print_phil(philo, philo->data, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_phil(philo, philo->data, "has taken a fork");
	print_phil(philo, philo->data, "is eating");
	pthread_mutex_lock(&philo->data->lock_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->lock_eat);
	pthread_mutex_lock(&philo->lock_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->lock_meal);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

void	sleep_think_phil(t_philo *philo)
{
	if (!end_if(philo))
		return ;
	print_phil(philo, philo->data, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	print_phil(philo, philo->data, "is thinking");
	pthread_mutex_lock(&philo->data->lock_death);
	pthread_mutex_lock(&philo->lock_meal);
	while ((philo->data->time_to_die - (get_time()
				- philo->last_meal) > philo->data->time_to_eat)
		&& philo->data->phil_died == 0)
	{
		pthread_mutex_unlock(&philo->data->lock_death);
		pthread_mutex_unlock(&philo->lock_meal);
		ft_usleep(1, philo->data);
		pthread_mutex_lock(&philo->data->lock_death);
		pthread_mutex_lock(&philo->lock_meal);
	}
	pthread_mutex_unlock(&philo->data->lock_death);
	pthread_mutex_unlock(&philo->lock_meal);
}
