/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:17:07 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/16 17:53:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if ((character >= '0' && character <= '9'))
	{
		return (1);
	}
	return (0);
}
