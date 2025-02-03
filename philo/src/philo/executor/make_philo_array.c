/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:05:19 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/03 17:31:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_array(t_philo **philo_array)
{
	size_t	i;

	i = 0;
	while (philo_array[i])
	{
		free_philo(philo_array[i]);
		i++;
	}
	free(philo_array);
}

static size_t	pointer_array_len(void **ptr_array)
{
	size_t	i;

	i = 0;
	while (ptr_array[i])
		i++;
	return (i);
}

t_philo	**make_philo_array(t_philo_info info, pthread_mutex_t **fork_array, \
		pthread_mutex_t *print)
{
	size_t	i;
	t_philo	**philo_array;

	philo_array = ft_calloc(sizeof(t_philo *) * \
			(pointer_array_len((void **) fork_array) + 1));
	if (!philo_array)
		return (NULL);
	i = 0;
	while (fork_array[i + 1])
	{
		info.id = i + 1;
		philo_array[i] = philo_make(info, print, \
				fork_array[i], fork_array[i + 1]);
		if (!philo_array[i])
			return (free_philo_array(philo_array), NULL);
		i++;
	}
	info.id = i + 1;
	philo_array[i] = philo_make(info, print, fork_array[i], fork_array[0]);
	if (!philo_array[i])
		return (free_philo_array(philo_array), NULL);
	return (philo_array);
}
