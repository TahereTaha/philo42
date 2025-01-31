/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:51:18 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/30 18:23:49 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo_state	get_philo_state(void)
{
	t_philo_state	state;

	pthread_mutex_init(&(state.lock), NULL);
	gettimeofday(&state.last_time_eaten, NULL);
	state.action = SLEAPING;
	state.times_eaten = 0;
	return (state);
}

t_philo	*philo_make(t_philo_info info, pthread_mutex_t *print, \
		pthread_mutex_t *rigth_fork, pthread_mutex_t *left_fork)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->info = info;
	philo->state = get_philo_state();
	philo->print = print;
	philo->rigth_fork = rigth_fork;
	philo->left_fork = left_fork;
	return (philo);
}
