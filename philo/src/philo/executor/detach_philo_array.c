/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_philo_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:18:37 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 16:32:31 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_philo_array(t_philo **philo_array)
{
	pthread_t	thread;
	size_t		i;

	i = 0;
	while (philo_array[i])
	{
		pthread_create(&thread, NULL, \
				(t_voidpp) philo_routine, philo_array[i]);
		pthread_detach(thread);
		i++;
	}
}
