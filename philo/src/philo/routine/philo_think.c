/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:47:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 09:45:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_take_fork(t_philo *philo)
{
	log_first_half(philo);
	printf("has taken a fork\n");
	pthread_mutex_unlock(philo->print);
}

static void	log_change_state(t_philo *philo)
{
	log_first_half(philo);
	printf("is thinking\n");
	philo->state.action = THINKING;
	pthread_mutex_unlock(philo->print);
	pthread_mutex_unlock(&philo->state.lock);
}

void	philo_think(t_philo *philo)
{
	log_change_state(philo);
	pthread_mutex_lock(philo->rigth_fork);
	log_take_fork(philo);
	pthread_mutex_lock(philo->left_fork);
	log_take_fork(philo);
	return ;
}

