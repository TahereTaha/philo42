/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:28:25 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/03 16:12:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	log_change_state(t_philo *philo)
{
	log_first_half(philo);
	printf("\033[0;33m");
	printf("is sleeping\n");
	printf("\033[0m");
	philo->state.action = SLEAPING;
	pthread_mutex_unlock(philo->print);
}

void	philo_sleep(t_philo *philo)
{
	log_change_state(philo);
	usleep(philo->info.time_to_sleep_ms * 1000);
	return ;
}
