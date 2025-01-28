/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:12:23 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 09:45:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_change_state(t_philo *philo)
{
	log_first_half(philo);
	printf("is eating\n");
	philo->state.action = EATING;
	gettimeofday(&philo->state.last_time_eaten, NULL);
	philo->state.times_eaten++;
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->state.lock);
}

void	philo_eat(t_philo *philo)
{
	log_change_state(philo);
	pthread_mutex_unlock(philo->rigth_fork);
	pthread_mutex_unlock(philo->left_fork);
	usleep(philo->info.time_to_eat_ms * 1000);
}
