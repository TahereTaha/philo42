/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:12:23 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 09:26:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_change_state(t_philo *philo)
{
	log_first_half(philo);
	printf("\033[0;37m");
	printf("is eating\n");
	printf("\033[0m");
	philo->state.action = EATING;
	gettimeofday(&philo->state.last_time_eaten, NULL);
	philo->state.times_eaten++;
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->state.lock);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->state.lock);
	log_change_state(philo);
	usleep(philo->info.time_to_eat_ms * 1000);
	pthread_mutex_unlock(philo->rigth_fork);
	pthread_mutex_unlock(philo->left_fork);
}
