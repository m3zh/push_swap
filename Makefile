# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 22:25:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/05/13 20:02:46 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC = inc/pushswap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	srcs/main.c \
	srcs/pushswap.c \
	srcs/input.c

OBJS = 	$(SRC:.c=.o)

LIBFT = libft/

$(NAME): $(OBJS) makelibft
	$(CC) $(CFLAGS) $(INC) $(OBJS) libft/*.a -o $(NAME) 

makelibft:
	$(MAKE) $(LIBFT)

clean:
	@rm $(OBJS)

fclean: clean
	@rm $(NAME)