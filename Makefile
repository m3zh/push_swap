# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 22:25:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/05/13 20:05:39 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHK = checker

INC = -I./inc

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

SRC = \
	srcs/main.c \
	srcs/pushswap.c \
	srcs/pushswap_utils.c \
	srcs/stack.c \
	srcs/stack_utils.c \
	srcs/small_sort.c \
	srcs/small_sortutils.c \
	srcs/sort_utils.c \
	srcs/ft_atoi.c

SRCB = \
	srcs/checker.c \
	srcs/checker_utils.c \
	srcs/checker_gnl.c \
	srcs/pushswap_utils.c \
	srcs/sort_utils.c \
	srcs/small_sortutils.c \
	srcs/stack.c \
	srcs/stack_utils.c \
	srcs/ft_atoi.c

OBJS = 	$(SRC:.c=.o)
OBJB = 	$(SRCB:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) 

all: $(NAME)

$(CHK): $(OBJB)
	$(CC) $(OBJB) $(CFLAGS) $(INC) -o $(CHK)

bonus: $(CHK)

clean:
	@rm -f $(OBJS) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(CHK)

re: fclean all

.PHONY: all clean fclean re bonus
