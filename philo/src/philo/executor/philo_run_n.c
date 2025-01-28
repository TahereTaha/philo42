/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:59:48 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**philo_run_n(t_philo_info philo_info, size_t philo_num)
{
	t_philo			**philo_array;
	pthread_mutex_t	**fork_array;
	pthread_mutex_t	*print;

	print = ft_mutex_init();
	if (!print)
		return (NULL);
	fork_array = make_fork_array(philo_num);
	if (!fork_array)
		return (ft_mutex_destroy(print), NULL);
	philo_array = make_philo_array(philo_info, fork_array, print);
	if (!philo_array)
	{
		ft_mutex_destroy(print);
		fork_array_destroy(fork_array);
		return (NULL);
	}
	detach_philo_array(philo_array);
	free(fork_array);
	return (philo_array);
}
