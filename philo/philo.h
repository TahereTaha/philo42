/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:47:10 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/28 16:54:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FT 42

//============================================//
//================== utils ===================//
//============================================//

typedef void *(*t_voidpp)(void *);

//	utils fuctions

void			*ft_calloc(size_t size);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_isspace(int c);

//============================================//
//================== philo ===================//
//============================================//

void			ft_mssleep(size_t ms);

//	the constructor and destroyer of mutex.

pthread_mutex_t	*ft_mutex_init(void);
void			ft_mutex_destroy(pthread_mutex_t *mutex);

//	philosofers code

typedef struct s_philo_info
{
	int			id;
	int			time_to_die_ms;
	int			time_to_eat_ms;
	int			time_to_sleep_ms;
	int			times_to_eat;
}	t_philo_info;

typedef enum e_philo_action
{
	THINKING,
	EATING,
	SLEAPING,
}	t_philo_action;

typedef struct s_philo_state
{
	pthread_mutex_t	lock;
	t_philo_action	action;
	struct timeval	last_time_eaten;
	int				times_eaten;
}	t_philo_state;

//	change the t_philo to the t_philo_state
//int		can_change_state(t_philo *philo);

typedef struct s_philo
{
	t_philo_info	info;
	t_philo_state	state;
	pthread_mutex_t	*print;
	pthread_mutex_t	*rigth_fork;
	pthread_mutex_t	*left_fork;
}	t_philo;

t_philo			*philo_make(t_philo_info info, pthread_mutex_t *print, \
		pthread_mutex_t *rigth_fork, pthread_mutex_t *left_fork);
void			free_philo(t_philo *philo);

//	this are the philo routines

void			philo_routine(t_philo *philo);

void			philo_think(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);

//	this exists for the purpos of debuging.
t_philo			**philo_run_1(t_philo_info philo);
t_philo			**philo_run_2(t_philo_info philo);
t_philo			**philo_run_3(t_philo_info philo);

t_philo			**philo_run_n(t_philo_info philo, size_t philo_num);
//	utils to the philo_run_n
pthread_mutex_t	**make_fork_array(size_t size);
void			fork_array_destroy(pthread_mutex_t **fork_array);
t_philo			**make_philo_array(t_philo_info info, \
		pthread_mutex_t **fork_array, pthread_mutex_t *print);
void			detach_philo_array(t_philo **philo_array);

//	debug print_functions

void			print_time_ms(struct timeval time);
//	this locks the print mutex
void			log_first_half(t_philo *philo);

void			print_philo_info(t_philo_info info);
void			print_philo_state(t_philo_state state);

void			print_philo(t_philo *philo);

//=============================================//
//================= parsing ===================//
//=============================================//

//	utils
int				is_int(char *str);

//	parsing
int				get_philo_info(t_philo_info *info, char **argv);

//============================================//
//================= waiter ===================//
//============================================//

void			waiter_run(t_philo **philo_array);

#endif
