/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:47:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 08:28:07 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_take_fork(t_philo *philo)
{
	log_first_half(philo);
	printf("\033[0;35m");
	printf("has taken a fork\n");
	printf("\033[0m");
	pthread_mutex_unlock(philo->print);
}

static void	log_change_state(t_philo *philo)
{
	log_first_half(philo);
	printf("\033[0;36m");
	printf("is thinking\n");
	printf("\033[0m");
	philo->state.action = THINKING;
	pthread_mutex_unlock(philo->print);
}

void	philo_think(t_philo *philo)
{
	log_change_state(philo);
	if (!(philo->info.id & 1))
		pthread_mutex_lock(philo->rigth_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	log_take_fork(philo);
	if (!(philo->info.id & 1))
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->rigth_fork);
	log_take_fork(philo);
	return ;
}
