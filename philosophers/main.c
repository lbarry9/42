/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:35:11 by lbarry            #+#    #+#             */
/*   Updated: 2024/03/01 01:58:39 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*phils;
	t_data	data;

	if (!check_args(argv, argc))
		return (printf("Error: insuitable arguments\n"), 1);
	init_data(&data, argv, argc);
	phils = malloc(sizeof(t_philo) * data.num_of_phils);
	if (!phils)
		return (1);
	data.everyphils = phils;
	init_phils(&data, phils);
	init_mutexes(&data, phils);
	if (data.num_of_phils == 1)
		return (only_one_phil(phils), free(phils), 0);
	init_threads(&data, phils);
	wait_for_threads(&data, phils);
	destroy_mutexes(&data, phils);
	free(phils);
	return (0);
}
