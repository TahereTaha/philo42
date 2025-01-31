/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:14:45 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 09:20:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_mutex_init(void)
{
	pthread_mutex_t	*mutex;

	mutex = ft_calloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	pthread_mutex_init(mutex, NULL);
	return (mutex);
}

void	ft_mutex_destroy(pthread_mutex_t *mutex)
{
	pthread_mutex_destroy(mutex);
	free(mutex);
}
