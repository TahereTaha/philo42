/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:50:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 07:10:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_time_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	gettimeofday(&philo->state.last_time_eaten, NULL);
	pthread_mutex_unlock(philo->print);
}

void	philo_routine(t_philo *philo)
{
	update_last_time_eaten(philo);
	if (!(philo->info.id & 1))
		usleep((philo->info.time_to_eat_ms * 1000) / 2);
	while (1)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return ;
}
