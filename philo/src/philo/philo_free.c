/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:34:40 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/15 12:38:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	free(philo);
}


void	debug_print_philo(t_philo *philo)
{
	printf("this is philo numer %i.\n", philo->info.id);
	printf("will take %ims to eat.\n", philo->info.time_to_eat_ms);
	printf("will eat %i times.\n", philo->info.times_to_eat);
	printf("and it has eaten %i times.\n", philo->state.times_eaten);
}
