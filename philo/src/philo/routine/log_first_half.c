/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_first_half.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:59:07 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/30 18:08:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_first_half(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(philo->print);
	if (philo->info.id % 2)
		printf("\033[0;31m");
	else
		printf("\033[0;32m");
	gettimeofday(&current_time, NULL);
	print_time_ms(current_time);
	printf(" %i ", philo->info.id);
	printf("\033[0m");
}

void	log_time(struct timeval time, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	print_time_ms(time);
	printf("\n");
	pthread_mutex_unlock(print);
}

void	log_current_time(pthread_mutex_t *print)
{
	struct timeval	current_time;

	pthread_mutex_lock(print);
	gettimeofday(&current_time, NULL);
	print_time_ms(current_time);
	printf("\n");
	pthread_mutex_unlock(print);
}
