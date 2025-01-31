/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:34:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/31 09:25:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time_ms(struct timeval time)
{
	size_t	time_ms;

	time_ms = 0;
	time_ms += time.tv_usec / 1000;
	time_ms += (time.tv_sec % 100000) * 1000;
	return (time_ms);
}

void	print_time_ms(struct timeval time)
{
	printf("%zu", get_time_ms(time));
}
