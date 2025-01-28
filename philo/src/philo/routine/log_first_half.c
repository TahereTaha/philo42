/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_first_half.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:59:07 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 09:34:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_first_half(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(philo->print);
	gettimeofday(&current_time, NULL);
	print_time_ms(current_time);
	printf(" %i ", philo->info.id);
}
