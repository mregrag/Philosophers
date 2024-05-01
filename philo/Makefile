# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 12:36:44 by mregrag           #+#    #+#              #
#    Updated: 2024/04/30 19:08:27 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC = src/main.c\
      src/init_data.c\
      src/philo_utils.c\
      src/errors.c\
      src/parsing.c\
      src/time.c\
      src/routine.c\
      src/threads.c\
      src/write_data.c\
      src/observer.c\
      src/get_set.c

OBJ	:= ${SRC:.c=.o}

CC 	= cc
RM 	= rm -rf

CFLAGS = -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o	: %.c ./include/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY:		all clean fclean re
