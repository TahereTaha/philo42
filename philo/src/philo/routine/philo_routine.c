/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:50:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 17:13:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(t_philo *philo)
{
	while (1)
	{
		if (philo->info.id & 1)
			usleep(20);
		pthread_mutex_lock(&philo->state.lock);
		if (philo->state.action == SLEAPING)
			philo_think(philo);
		else if (philo->state.action == THINKING)
			philo_eat(philo);
		else if (philo->state.action == EATING)
			philo_sleep(philo);
		if (philo->state.times_eaten == philo->info.times_to_eat)
			break ;
	}
	while (1)
		usleep(1000000);
	return ;
}
