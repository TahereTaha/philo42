/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:47:55 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 08:37:35 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_philo *philo)
{
	log_first_half(philo);
	printf("died\n");
}

static int	check_philo(t_philo *philo)
{
	size_t			last_time_eaten;
	size_t			current_time;
	struct timeval	time;

	pthread_mutex_lock(&philo->state.lock);
	gettimeofday(&time, NULL);
	current_time = get_time_ms(time);
	last_time_eaten = get_time_ms(philo->state.last_time_eaten);
	if (-last_time_eaten + current_time > \
			(unsigned long)philo->info.time_to_die_ms)
	{
		print_death(philo);
		return (1);
	}
	if (philo->state.times_eaten >= philo->info.times_to_eat)
	{
		pthread_mutex_unlock(&philo->state.lock);
		return (2);
	}
	pthread_mutex_unlock(&philo->state.lock);
	return (0);
}

static int	check_to_stop(t_philo **philo_array)
{
	size_t	i;
	size_t	return_val;
	size_t	all_finished;

	all_finished = 1;
	i = 0;
	while (philo_array[i])
	{
		return_val = check_philo(philo_array[i]);
		if (return_val == 1)
			return (1);
		if (return_val != 2)
			all_finished = 0;
		i++;
	}
	if (all_finished)
		return (1);
	return (0);
}

void	waiter_run(t_philo **philo_array)
{
	usleep(philo_array[0]->info.time_to_die_ms * 1000);
	while (1)
	{
		if (check_to_stop(philo_array))
			break ;
		usleep(500);
	}
	free(philo_array);
}
