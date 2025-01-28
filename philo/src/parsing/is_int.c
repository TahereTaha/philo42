/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:21:10 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/17 15:54:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	returns 1 on overflow of a int
int	ps_intoverflow(char *str, int sign)
{
	long	first;
	long	second;
	int		i;

	i = 0;
	first = 0;
	second = 0;
	while (ft_isdigit(str[i]))
	{
		first = (first * 10) + (str[i] - '0');
		if (first < second)
			return (1);
		if ((sign && first > 2147483648) || (!sign && first > 2147483647))
			return (1);
		second = first;
		i++;
	}
	return (0);
}

//	returns a 1 if there is no overflow and there are only numbers and sign
int	is_int(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = 1;
	if (ps_intoverflow(&str[i], sign))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
