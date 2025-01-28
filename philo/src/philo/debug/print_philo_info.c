/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:34:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/17 16:45:43 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_info(t_philo_info info)
{
	printf("the philo %i info is\n", info.id);
	printf("\ttime to die ms > %i\n", info.time_to_die_ms);
	printf("\ttime to eat ms > %i\n", info.time_to_eat_ms);
	printf("\ttime to sleep ms > %i\n", info.time_to_sleep_ms);
	printf("\ttimes to eat > %i\n", info.times_to_eat);
}
