/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:03:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/17 16:47:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_philo_action(t_philo_action action)
{
	printf("the philo is doing ");
	if (action == THINKING)
		printf("THINKING");
	else if (action == EATING)
		printf("EATING");
	else if (action == SLEAPING)
		printf("SLEAPNIG");
	printf("\n");
}

static void	print_philo_last_time_eaten(struct timeval last_time_eaten)
{
	printf("the last time eaten is ");
	print_time_ms(last_time_eaten);
	printf("\n");
}

void	print_philo_state(t_philo_state state)
{
	printf("the philo state is:\n");
	print_philo_action(state.action);
	print_philo_last_time_eaten(state.last_time_eaten);
	printf("the times eaten are: %i\n", state.times_eaten);
}
