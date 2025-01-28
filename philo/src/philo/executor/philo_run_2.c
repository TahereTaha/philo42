/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:46:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 09:51:35 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo			**philo_run_2(t_philo_info philo)
{
	t_philo			**philo_array;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*print;
	pthread_t		thread;

	fork1 = ft_mutex_init();
	fork2 = ft_mutex_init();
	print = ft_mutex_init();
	philo_array = ft_calloc(sizeof(t_philo *) * 2);
	philo.id = 1;
	philo_array[0] = philo_make(philo, print, fork1, fork2);
	philo.id = 2;
	philo_array[1] = philo_make(philo, print, fork2, fork1);
	pthread_create(&thread, NULL, (t_voidpp) philo_routine, philo_array[0]);
	pthread_detach(thread);
	pthread_create(&thread, NULL, (t_voidpp) philo_routine, philo_array[1]);
	pthread_detach(thread);
	return (philo_array);
}
