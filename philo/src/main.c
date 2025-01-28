/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:46:28 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 17:26:01 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	read_args(int argc, char **argv, t_philo_info *philo_info)
{
	int	philo_num;

	if (argc != 4 && argc != 5)
	{
		ft_putstr_fd("the args are not correct\n", 2);
		return (-1);
	}
	philo_num = get_philo_info(philo_info, argv);
	if (philo_num == -1)
	{
		ft_putstr_fd("the args are not correct\n", 2);
		return (-1);
	}
	return (philo_num);
}

int	main(int argc, char **argv)
{
	t_philo_info	philo_info;
	int				philo_num;
	char			buf[2];
	t_philo			**philo_array;

	printf("this is philosofers.\n");
	philo_num = read_args(argc, argv, &philo_info);
	if (philo_num < 0)
		return (1);
	philo_array = philo_run_n(philo_info, philo_num);
	if (!philo_array)
	{
		ft_putstr_fd("malloc error");
		return (1);
	}
	read(0, buf, 1);
	return (0);
}

//	old main
/*
t_philo_info	set_philo_info()
{
	t_philo_info philo_info;

	philo_info.id = 1;
	philo_info.time_to_eat_ms = 20;
	philo_info.time_to_die_ms = 20;
	philo_info.times_to_eat = 2;
	return (philo_info);
}

t_philo_state	set_philo_state()
{
	t_philo_state	philo_state;

	philo_state.action = THINKING;
	philo_state.times_eaten = 0;
	gettimeofday(&philo_state.last_time_eaten, NULL);
	return (philo_state);
}

int	main(void)
{
//	int				philo_setings[6] = {20, 2, 50, 3, 10, 7};
	t_print			*print;
	t_philo			*philo;
	t_philo_info	philo_info;
	t_philo_state	philo_state;

	printf("this is philosofers.\n");
	print = init_print();
	if (!print)
		return (1);
	philo_info = set_philo_info();
	philo_state = set_philo_state();
	philo = init_philo(philo_info, philo_state, print);
	if (!print)
		return (free_print(print), 1);
//	run_philo(philo);
//	debug_print_philo(philo);
	free_print(print);
	return (FT);
}
*/
