/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:43:13 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 09:46:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo			**philo_run_1(t_philo_info philo)
{
	t_philo			**philo_array;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	pthread_t		thread;

	philo.id = 1;
	fork = ft_mutex_init();
	print = ft_mutex_init();
	philo_array = ft_calloc(sizeof(t_philo *) * 2);
	philo_array[0] = philo_make(philo, print, fork, fork);
	pthread_create(&thread, NULL, (t_voidpp) philo_routine, philo_array[0]);
	pthread_detach(thread);
	return (philo_array);
}
