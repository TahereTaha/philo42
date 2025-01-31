/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:24:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 09:24:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_array_destroy(pthread_mutex_t **fork_array)
{
	size_t	i;

	if (!fork_array)
		return ;
	i = 0;
	while (fork_array[i])
	{
		ft_mutex_destroy(fork_array[i]);
		i++;
	}
	free(fork_array);
}

pthread_mutex_t	**make_fork_array(size_t size)
{
	pthread_mutex_t	**fork_array;
	size_t			i;

	fork_array = ft_calloc(sizeof(pthread_mutex_t *) * (size + 1));
	if (!fork_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		fork_array[i] = ft_mutex_init();
		if (!fork_array[i])
			return (fork_array_destroy(fork_array), NULL);
		i++;
	}
	return (fork_array);
}
