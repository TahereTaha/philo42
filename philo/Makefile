# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 06:49:13 by tatahere          #+#    #+#              #
#    Updated: 2025/02/03 17:30:46 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/

RF		=	rm -rf
CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -I./ -O3 #-g -fsanitize=thread

NAME	=	philo

GENERAL_OBJ		:=	main.o		\
					mutex.o		\
					waiter.o		\

OBJ				+= $(GENERAL_OBJ)

UTILS_OBJ		:=	ft_calloc.o			\
					ft_atoi.o			\
					ft_putstr_fd.o		\
					ft_strlen.o			\
					ft_isdigit.o		\
					ft_isspace.o		\

OBJ				+= $(UTILS_OBJ)

PHILO_OBJ		:=	philo_make.o				\
					philo_free.o				\
					philo_run_n.o				\
					fork_array.o				\
					make_philo_array.o			\
					detach_philo_array.o		\

PHILO_DEBUG_OBJ	:=	print_philo_info.o			\
					print_philo_state.o			\
					print_philo.o				\
					print_time_ms.o				\

PHILO_OBJ		+=	$(PHILO_DEBUG_OBJ)

PHILO_ROUTINE_OBJ	:=	log_first_half.o			\
						philo_eat.o			\
						philo_sleep.o				\
						philo_think.o				\
						philo_routine.o				\

PHILO_OBJ		+=	$(PHILO_ROUTINE_OBJ)


OBJ				+=	$(PHILO_OBJ)

MONITOR_OBJ		:=	\

OBJ				+= $(MONITOR_OBJ)

PARSING_OBJ		:=	get_philo_info.o	\
					is_int.o			\

OBJ				+= $(PARSING_OBJ)

OBJ		:=	$(addprefix $(BIN_DIR), $(OBJ))

HDR		=	philo.h		\

VPATH	= $(SRC_DIR)
VPATH	+= $(SRC_DIR)utils/
VPATH	+= $(SRC_DIR)parsing/
VPATH	+= $(SRC_DIR)philo/
VPATH	+= $(SRC_DIR)philo/debug/
VPATH	+= $(SRC_DIR)philo/routine/
VPATH	+= $(SRC_DIR)philo/executor/
VPATH	+= $(SRC_DIR)waiter/

all	:	$(BIN_DIR) $(NAME)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(NAME)	: $(OBJ) Makefile $(HDR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BIN_DIR)%.o :	%.c	Makefile $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RF) $(BIN_DIR)

fclean	:	clean
	$(RF) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
