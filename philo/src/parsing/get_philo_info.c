/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:51:50 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/17 16:01:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_number(int *err_ref, char *str)
{
	int	num;

	*err_ref = 1;
	if (!is_int(str))
		return (0);
	num = ft_atoi(str);
	if (num < 0)
		return (0);
	*err_ref = 0;
	return (num);
}

//	this returns the amount of philosofers
//in case of error it will return a neganive number
int	get_philo_info(t_philo_info *info, char **argv)
{
	int	err;
	int	num_of_philo;

	info->id = 0;
	err = 0;
	num_of_philo = get_number(&err, argv[1]);
	if (err)
		return (-1);
	info->time_to_die_ms = get_number(&err, argv[2]);
	if (err)
		return (-1);
	info->time_to_eat_ms = get_number(&err, argv[3]);
	if (err)
		return (-1);
	info->time_to_sleep_ms = get_number(&err, argv[4]);
	if (err)
		return (-1);
	info->times_to_eat = -1;
	if (!argv[5])
		return (num_of_philo);
	info->times_to_eat = get_number(&err, argv[5]);
	if (err)
		return (-1);
	return (num_of_philo);
}
